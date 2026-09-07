// Code ran using multipass on linux 


# 1. Start the VM
multipass start kernel-dev

# 2. Re-mount your project folder
multipass mount /home/paschalolo/studyWeb/device_driver kernel-dev:/home/ubuntu/driver

# 3. Open the shell
multipass shell kernel-dev

# unmount and exit the process 
multipass umount kernel-dev 
multipass stop kernel-dev
