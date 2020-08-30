## What is this?

Workarounds for some Ricoh SP printers not working on Linux. Fork of abandoned <https://github.com/madlynx/ricoh-sp100> repository.

I only added some PPDs and other features proposed by other people (<https://github.com/madlynx/ricoh-sp100/issues> and <https://github.com/madlynx/ricoh-sp100/pulls>). Also refactored the code, especially in _pstoricohddst-gdi_.

## Installation

1) Open the terminal and clone the repository from Github:

        git clone https://github.com/mishta-real/ricoh-sp100.git
        cd ricoh-sp100

2) Execute _check-requirements.sh_ script. It will check whether all required packages are installed and available or not:

        ./check-requirements.sh

3) Install missing packages with your package manager or manually.

4) If you have models __Aficio SP 100__, __SP 112__, __SP 202SN__ or __SP 204__, then copy _pstoricohddst-gdi_ into directory with CUPS filters (usually `/usr/lib/cups/filter`):

        sudo cp pstoricohddst-gdi /usr/lib/cups/filter

   If you have __SP 210__ or __SP 211__, copy _rastertolilo_ instead:

        sudo cp rastertolilo /usr/lib/cups/filter

5) Make sure the filter has permissions of __0555__ and is owned by __root:root__:

        sudo chmod 0555 /usr/lib/cups/filter/pstoricohddst-gdi
        sudo chown root:root /usr/lib/cups/filter/pstoricohddst-gdi

   or:

        sudo chmod 0555 /usr/lib/cups/filter/rastertolilo
        sudo chown root:root /usr/lib/cups/filter/rastertolilo

6) Make sure the printer is connected to the computer and turned on, then configure it with CUPS Web Interface: open your browser, type 'localhost:631', go to 'Administration' > 'Add Printer'. Find your printer and choose it, then press 'Continue'. After that, provide a PPD file with the name of your printer from 'ppd' directory. Finally, press 'Add Printer', then 'Set Default Options'.

7) As you finish step 6, go to the 'Printers' > _Your printer_ > 'Maintenance' > 'Print test page'. If the printer is printing and the page is not blank, you configured it correctly.

8) __If the printer does not print after the first job__, then you should try to repeat the steps described here (replace <queue\> with the name of your printer): 

   <https://wiki.ubuntu.com/DebuggingPrintingProblems#USB_printer_does_not_print_or_prints_garbage>

   If the issue persists, you need to reset the USB port the printer is connected to. In terminal, go into the repository and execute:

        sudo ./resetusb.sh

   Then try to run the job again.

## See also
- <https://wiki.archlinux.org/index.php/CUPS/Troubleshooting>
- <https://wiki.ubuntu.com/DebuggingPrintingProblems>
