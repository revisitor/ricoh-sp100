## What is this?

Workarounds for some Ricoh DDST printers not working on Linux. Fork of abandoned <https://github.com/madlynx/ricoh-sp100> repository.

## Installation

1) Clone the repository from Github:

        git clone https://github.com/mishta-real/ricoh-sp100.git
        cd ricoh-sp100

2) Open terminal, execute 'check-requirements' script. It will check whether all required packages are installed and available or not:

        ./check-requirements

3) Install missing packages with your package manager.

4) Copy 'pstoricohddst-gdi' into directory for CUPS filters (usually `/usr/lib/cups/filter`):

        sudo cp pstoricohddst-gdi /usr/lib/cups/filter

5) Make sure it has permissions of 0555 and is owned by root:root:

        sudo chmod 0555 /usr/lib/cups/filter/pstoricohddst-gdi
        sudo chown root:root /usr/lib/cups/filter/pstoricohddst-gdi

6) Make sure the printer is connected to the computer and turned on, then configure it with CUPS Web Interface: open your browser, type 'localhost:631', go to 'Administration' > 'Add Printer'. Find your printer and choose it, then press 'Continue'. After that, provide a PPD file with the name of your printer from 'ppd' folder. Finally, press 'Add Printer', then 'Set Default Options'.

7) As you finish step 6, go to the 'Printers' > Your printer > 'Maintenance' > 'Print test page'. If the printer is printing and the page is not blank, you configured it correctly.

8) If your printer does not print after the first job, then you need to reset the USB port the printer is connected to. In terminal, go into the repository and execute `sudo ./resetusb_script`. Then try to run the job again.

## See also
- <https://wiki.archlinux.org/index.php/CUPS/Troubleshooting>
- <https://wiki.ubuntu.com/DebuggingPrintingProblems>