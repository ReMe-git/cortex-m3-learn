.syntax unified
.cpu cortex-m3
.thumb

.global _start
.global _Main_Stack_Top
.global vectors_table
.type vectors_table,%object

.section .text.vectors_table
vectors_table:
	.word _Main_Stack_Top
	.word	Reset_Handler
  .word	NMI_Handler
	.word	HardFault_Handler
	.word	MemManage_Handler
	.word	BusFault_Handler
	.word	UsageFault_Handler
	.word	0
	.word	0
	.word	0
	.word	0
	.word	SVC_Handler
	.word	DebugMon_Handler
	.word	0
	.word	PendSV_Handler
	.word	SysTick_Handler
.size vectors_table,.-vectors_table

.weak	NMI_Handler
.weak	HardFault_Handler
.weak	MemManage_Handler
.weak	BusFault_Handler
.weak	UsageFault_Handler
.weak	SVC_Handler
.weak	DebugMon_Handler
.weak	PendSV_Handler
.weak	SysTick_Handler

.thumb_set	NMI_Handler, Default_Handler
.thumb_set	HardFault_Handler, Default_Handler
.thumb_set	MemManage_Handler, Default_Handler
.thumb_set	BusFault_Handler, Default_Handler
.thumb_set	UsageFault_Handler, Default_Handler
.thumb_set	SVC_Handler, Default_Handler
.thumb_set	DebugMon_Handler, Default_Handler
.thumb_set	PendSV_Handler, Default_Handler
.thumb_set	SysTick_Handler, Default_Handler

.section .text.Default_Handler
.global Default_Handler
.type Default_Handler,%function
Default_Handler:
  b Default_Handler
.size Default_Handler, .-Default_Handler

.section .text.Reset_Handler
.global Reset_Handler
.type Reset_Handler,%function
Reset_Handler:
  bl system_init
  bl main
  bl Exit
.size Reset_Handler, .-Reset_Handler

.global system_init
.type system_init,%function
.weak system_init
.thumb_set system_init,Default_Handler

.global main
.type main,%function
.weak main
.thumb_set main,Default_Handler

.global Exit
.type Exit,%function
.weak Exit
.thumb_set Exit,Default_Handler
