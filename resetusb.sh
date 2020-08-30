#!/usr/bin/env bash

# This script automatically finds bus and device IDs
# and launches the executable. When complete, the executable is removed.

# Run the script with sudo if your printer does not print after first job.

bus_id=$(lsusb | grep Ricoh | cut -d" " -f2)

if [[ -z $bus_id ]]; then
  printf "No Ricoh printer found. Make sure it's connected to the computer and turned on.\\n"
  exit 1
fi

dev_id=$(lsusb | grep Ricoh | cut -d" " -f4 | cut -c1-3)

exec_name="resetusb"
cc resetusb.c -o "$exec_name"

"./$exec_name" "/dev/bus/usb/$bus_id/$dev_id"

rm -f "$exec_name"

exit 0
