echo "git pull"
git pull
echo "make all"
make all -j8
echo "make install"
sudo make install
echo "run"
sudo kamailio -M 8 -E -e -DD -dddd > ~/klog.txt 2>&1
