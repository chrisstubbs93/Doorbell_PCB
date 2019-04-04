@ECHO OFF
cls
cd "C:\Users\Chris\Documents\GitHub\Doorbell\Docs"

echo =========================================================================================
echo Generating docs XML with doxygen.
call doxygen doxygen\Doxyfile

echo =========================================================================================
echo Generating HTML with Sphinx.
call make.bat html

echo =========================================================================================
echo Done.