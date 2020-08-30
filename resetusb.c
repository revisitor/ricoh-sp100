/*
 * usbreset -- send an USB port reset to an USB device
 * Use it when printer doesn't print after first job.
 * 
 * https://github.com/madlynx/ricoh-sp100/issues/59
 *
 * Source code: marc.info/?l=linux-usb&m=121459435621262&w=2
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <linux/usbdevice_fs.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        fprintf(
            stderr,
            "Usage: usbreset /dev/bus/usb/<bus-number>/<device-number>\n"
        );
        return 1;
    }

    const char *filename = argv[1];

    int fd = open(filename, O_WRONLY);
    if (fd < 0) {
        perror("Error opening output file.");
        return 1;
    }

    printf("Resetting USB device %s ...\n", filename);

    int rc = ioctl(fd, USBDEVFS_RESET, 0);
    if (rc < 0) {
        perror("Error in ioctl.");
        return 1;
    }

    printf("Reset successful.\n");

    close(fd);

    return 0;
}
