#!/bin/sh

make -C /lib/modules/$(uname -r)/build M=$(pwd) balloon_probe.ko
