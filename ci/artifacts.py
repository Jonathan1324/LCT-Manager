import logging
from pathlib import Path
import shutil
import os
import sys
import stat

logger = logging.getLogger("ci")

def stage(debug: bool) -> bool:
    logger.debug("Staging the artifacts")

    dist_dir = Path("dist")

    dist_bin = Path(f"{dist_dir}/bin")
    dist_bin.mkdir(parents=True, exist_ok=True)

    build_type = "debug" if debug else "release"
    binaries = Path(f"build/{build_type}/binaries.txt")

    if not binaries.exists():
        logger.error(f"{binaries} does not exist")
        return False
    
    with binaries.open() as f:
        for line in f:
            bin_name = line.strip()
            if not bin_name: continue
            binary = Path(bin_name)
            if binary.exists():
                dst = dist_bin / binary.name
                shutil.copy2(binary, dst)
                logger.debug(f"Copied {binary} to {dst}")
                if sys.platform != "win32":
                    st = os.stat(dst)
                    os.chmod(dst, st.st_mode | stat.S_IEXEC)
                    logger.debug(f"Set executable permission for {dst}")
            else:
                logger.warning(f"{binary} does not exist")
    
    logger.info(f"Staged {len(list(dist_bin.iterdir()))} binaries in dist/bin")

    binaries.unlink()
    logger.debug(f"Deleted {binaries}")

    return True