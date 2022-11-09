# Basics of ARM Cortex based microcontroller


<a href="https://github.com/RohitAkurdekar/MicroControllers/blob/main/ARM_Cortex/Theory/MC_BASICS.pdf">BASICs.pdf</a>

<h2>Size of databus</h2>
&nbsp;&nbsp; Bits of data stored on each Address. <br>
<h2>Size of address bus</h2>
2^n = Size of memory space. <br>
--- Where, n is a total numbers of address bus.<br><br>

For example, <br>
Memory space is 4096 Bytes with each address of 8 bits. <br>
Size of Databus     = 8  bits.<br>
Size of Address bus = 12 bits.<br>
i.e. 2^12 = 4096<br>

----------------------------------------------------------------------------------------

<h2>External bus</h2>
A bus used to connect external peripherals is called as an external bus. <br>

----------------------------------------------------------------------------------------
<br>

<h2>Flags</h2>
<ul>
<li>Processor flag - Status of result</li>
<li>Auxilary  flag - Carry from LS nibble to Upper side nibble</li>
<li>Carry     flag - Carry out of th MS bit of result</li>
<li>Negative  flag - If MS bit of resultr is set</li>
<li>Overflow  flag - If arithmetic overflow occurs</li>
<li>Sign      flag - Set for negative sign</li>

MS: Most Significant<br>
</ul>

<br>

----------------------------------------------------------------------------------------
<br>

<h2>Interrupts flags</h2>
<ul>
    <li>Interrupt Enable  - Ready to serve the incoming interrupt</li>
    <li>Interrupt Masking - Not ready to serve the incoming interrupt</li>
</ul>


<br>

----------------------------------------------------------------------------------------
<br>

<h2>MicroProcessor</h2>
Peripherals, Timers, IOs are seperately connected/interfaced with it.

<h2>MicroController</h2>
Peripherals, Timers, IOs are combined in it.

<br>

----------------------------------------------------------------------------------------
<br>

<h3>Mobile phones have SoC[System on Chip]</h3>

<br>

----------------------------------------------------------------------------------------
<br>

<h2>Von-Neuman </h2>
<ul>
<li>Shares same bus for address and data operations.</li>
<li>Can operate either only Address or Data ata a single time.</li>
<li>Bottleneck on buses.</li>
<li>Pin count is less.</li>
<li>Personal Desktops uses this architecture</li>
<li>Ex- x86,8086</li>
</ul>

<h2>Harward </h2>
<ul>
<li>Shares seperate bus for address and data operations.</li>
<li>Faster in operations</li>
<li>Ex-8048,PIC,DSPs</li>
</ul>

<br>

<img src="https://raw.githubusercontent.com/RohitAkurdekar/MicroControllers/main/ARM_Cortex/Theory/Endians_defs.jpg">



<br>

<br>

----------------------------------------------------------------------------------------
<br>


&copy; 2022, Rohit Akurdekar