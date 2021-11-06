
test5_5_5_6：     文件格式 elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <clock@plt-0x10>:
    1020:	ff 35 e2 2f 00 00    	push   0x2fe2(%rip)        # 4008 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 e4 2f 00 00    	jmp    *0x2fe4(%rip)        # 4010 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001030 <clock@plt>:
    1030:	ff 25 e2 2f 00 00    	jmp    *0x2fe2(%rip)        # 4018 <clock@GLIBC_2.2.5>
    1036:	68 00 00 00 00       	push   $0x0
    103b:	e9 e0 ff ff ff       	jmp    1020 <_init+0x20>

0000000000001040 <printf@plt>:
    1040:	ff 25 da 2f 00 00    	jmp    *0x2fda(%rip)        # 4020 <printf@GLIBC_2.2.5>
    1046:	68 01 00 00 00       	push   $0x1
    104b:	e9 d0 ff ff ff       	jmp    1020 <_init+0x20>

Disassembly of section .text:

0000000000001050 <main>:
    1050:	41 54                	push   %r12
    1052:	55                   	push   %rbp
    1053:	53                   	push   %rbx
    1054:	e8 d7 ff ff ff       	call   1030 <clock@plt>
    1059:	49 89 c4             	mov    %rax,%r12
    105c:	e8 cf ff ff ff       	call   1030 <clock@plt>
    1061:	48 89 c5             	mov    %rax,%rbp
    1064:	e8 c7 ff ff ff       	call   1030 <clock@plt>
    1069:	48 89 ee             	mov    %rbp,%rsi
    106c:	48 8d 3d 95 0f 00 00 	lea    0xf95(%rip),%rdi        # 2008 <_IO_stdin_used+0x8>
    1073:	48 89 c3             	mov    %rax,%rbx
    1076:	4c 29 e6             	sub    %r12,%rsi
    1079:	31 c0                	xor    %eax,%eax
    107b:	e8 c0 ff ff ff       	call   1040 <printf@plt>
    1080:	48 29 eb             	sub    %rbp,%rbx
    1083:	48 8d 3d 9e 0f 00 00 	lea    0xf9e(%rip),%rdi        # 2028 <_IO_stdin_used+0x28>
    108a:	31 c0                	xor    %eax,%eax
    108c:	48 89 de             	mov    %rbx,%rsi
    108f:	e8 ac ff ff ff       	call   1040 <printf@plt>
    1094:	5b                   	pop    %rbx
    1095:	31 c0                	xor    %eax,%eax
    1097:	5d                   	pop    %rbp
    1098:	41 5c                	pop    %r12
    109a:	c3                   	ret    
    109b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

00000000000010a0 <_start>:
    10a0:	f3 0f 1e fa          	endbr64 
    10a4:	31 ed                	xor    %ebp,%ebp
    10a6:	49 89 d1             	mov    %rdx,%r9
    10a9:	5e                   	pop    %rsi
    10aa:	48 89 e2             	mov    %rsp,%rdx
    10ad:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    10b1:	50                   	push   %rax
    10b2:	54                   	push   %rsp
    10b3:	4c 8d 05 b6 01 00 00 	lea    0x1b6(%rip),%r8        # 1270 <__libc_csu_fini>
    10ba:	48 8d 0d 3f 01 00 00 	lea    0x13f(%rip),%rcx        # 1200 <__libc_csu_init>
    10c1:	48 8d 3d 88 ff ff ff 	lea    -0x78(%rip),%rdi        # 1050 <main>
    10c8:	ff 15 12 2f 00 00    	call   *0x2f12(%rip)        # 3fe0 <__libc_start_main@GLIBC_2.2.5>
    10ce:	f4                   	hlt    
    10cf:	90                   	nop

00000000000010d0 <deregister_tm_clones>:
    10d0:	48 8d 3d 61 2f 00 00 	lea    0x2f61(%rip),%rdi        # 4038 <__TMC_END__>
    10d7:	48 8d 05 5a 2f 00 00 	lea    0x2f5a(%rip),%rax        # 4038 <__TMC_END__>
    10de:	48 39 f8             	cmp    %rdi,%rax
    10e1:	74 15                	je     10f8 <deregister_tm_clones+0x28>
    10e3:	48 8b 05 ee 2e 00 00 	mov    0x2eee(%rip),%rax        # 3fd8 <_ITM_deregisterTMCloneTable>
    10ea:	48 85 c0             	test   %rax,%rax
    10ed:	74 09                	je     10f8 <deregister_tm_clones+0x28>
    10ef:	ff e0                	jmp    *%rax
    10f1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10f8:	c3                   	ret    
    10f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001100 <register_tm_clones>:
    1100:	48 8d 3d 31 2f 00 00 	lea    0x2f31(%rip),%rdi        # 4038 <__TMC_END__>
    1107:	48 8d 35 2a 2f 00 00 	lea    0x2f2a(%rip),%rsi        # 4038 <__TMC_END__>
    110e:	48 29 fe             	sub    %rdi,%rsi
    1111:	48 89 f0             	mov    %rsi,%rax
    1114:	48 c1 ee 3f          	shr    $0x3f,%rsi
    1118:	48 c1 f8 03          	sar    $0x3,%rax
    111c:	48 01 c6             	add    %rax,%rsi
    111f:	48 d1 fe             	sar    %rsi
    1122:	74 14                	je     1138 <register_tm_clones+0x38>
    1124:	48 8b 05 c5 2e 00 00 	mov    0x2ec5(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable>
    112b:	48 85 c0             	test   %rax,%rax
    112e:	74 08                	je     1138 <register_tm_clones+0x38>
    1130:	ff e0                	jmp    *%rax
    1132:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    1138:	c3                   	ret    
    1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001140 <__do_global_dtors_aux>:
    1140:	f3 0f 1e fa          	endbr64 
    1144:	80 3d ed 2e 00 00 00 	cmpb   $0x0,0x2eed(%rip)        # 4038 <__TMC_END__>
    114b:	75 33                	jne    1180 <__do_global_dtors_aux+0x40>
    114d:	55                   	push   %rbp
    114e:	48 83 3d a2 2e 00 00 	cmpq   $0x0,0x2ea2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1155:	00 
    1156:	48 89 e5             	mov    %rsp,%rbp
    1159:	74 0d                	je     1168 <__do_global_dtors_aux+0x28>
    115b:	48 8b 3d ce 2e 00 00 	mov    0x2ece(%rip),%rdi        # 4030 <__dso_handle>
    1162:	ff 15 90 2e 00 00    	call   *0x2e90(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1168:	e8 63 ff ff ff       	call   10d0 <deregister_tm_clones>
    116d:	c6 05 c4 2e 00 00 01 	movb   $0x1,0x2ec4(%rip)        # 4038 <__TMC_END__>
    1174:	5d                   	pop    %rbp
    1175:	c3                   	ret    
    1176:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    117d:	00 00 00 
    1180:	c3                   	ret    
    1181:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
    1188:	00 00 00 00 
    118c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001190 <frame_dummy>:
    1190:	f3 0f 1e fa          	endbr64 
    1194:	e9 67 ff ff ff       	jmp    1100 <register_tm_clones>
    1199:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000011a0 <poly>:
    11a0:	66 0f 28 d8          	movapd %xmm0,%xmm3
    11a4:	f2 0f 10 07          	movsd  (%rdi),%xmm0
    11a8:	48 85 f6             	test   %rsi,%rsi
    11ab:	78 2c                	js     11d9 <poly+0x39>
    11ad:	48 8d 44 f7 08       	lea    0x8(%rdi,%rsi,8),%rax
    11b2:	66 0f 28 cb          	movapd %xmm3,%xmm1
    11b6:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    11bd:	00 00 00 
    11c0:	f2 0f 10 17          	movsd  (%rdi),%xmm2
    11c4:	48 83 c7 08          	add    $0x8,%rdi
    11c8:	f2 0f 59 d1          	mulsd  %xmm1,%xmm2
    11cc:	f2 0f 59 cb          	mulsd  %xmm3,%xmm1
    11d0:	f2 0f 58 c2          	addsd  %xmm2,%xmm0
    11d4:	48 39 f8             	cmp    %rdi,%rax
    11d7:	75 e7                	jne    11c0 <poly+0x20>
    11d9:	c3                   	ret    
    11da:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000011e0 <polyh>:
    11e0:	66 0f 28 c8          	movapd %xmm0,%xmm1
    11e4:	f2 0f 10 04 f7       	movsd  (%rdi,%rsi,8),%xmm0
    11e9:	48 83 ee 01          	sub    $0x1,%rsi
    11ed:	78 10                	js     11ff <polyh+0x1f>
    11ef:	90                   	nop
    11f0:	f2 0f 59 c1          	mulsd  %xmm1,%xmm0
    11f4:	f2 0f 58 04 f7       	addsd  (%rdi,%rsi,8),%xmm0
    11f9:	48 83 ee 01          	sub    $0x1,%rsi
    11fd:	73 f1                	jae    11f0 <polyh+0x10>
    11ff:	c3                   	ret    

0000000000001200 <__libc_csu_init>:
    1200:	f3 0f 1e fa          	endbr64 
    1204:	41 57                	push   %r15
    1206:	4c 8d 3d db 2b 00 00 	lea    0x2bdb(%rip),%r15        # 3de8 <__frame_dummy_init_array_entry>
    120d:	41 56                	push   %r14
    120f:	49 89 d6             	mov    %rdx,%r14
    1212:	41 55                	push   %r13
    1214:	49 89 f5             	mov    %rsi,%r13
    1217:	41 54                	push   %r12
    1219:	41 89 fc             	mov    %edi,%r12d
    121c:	55                   	push   %rbp
    121d:	48 8d 2d cc 2b 00 00 	lea    0x2bcc(%rip),%rbp        # 3df0 <__do_global_dtors_aux_fini_array_entry>
    1224:	53                   	push   %rbx
    1225:	4c 29 fd             	sub    %r15,%rbp
    1228:	48 83 ec 08          	sub    $0x8,%rsp
    122c:	e8 cf fd ff ff       	call   1000 <_init>
    1231:	48 c1 fd 03          	sar    $0x3,%rbp
    1235:	74 1f                	je     1256 <__libc_csu_init+0x56>
    1237:	31 db                	xor    %ebx,%ebx
    1239:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    1240:	4c 89 f2             	mov    %r14,%rdx
    1243:	4c 89 ee             	mov    %r13,%rsi
    1246:	44 89 e7             	mov    %r12d,%edi
    1249:	41 ff 14 df          	call   *(%r15,%rbx,8)
    124d:	48 83 c3 01          	add    $0x1,%rbx
    1251:	48 39 dd             	cmp    %rbx,%rbp
    1254:	75 ea                	jne    1240 <__libc_csu_init+0x40>
    1256:	48 83 c4 08          	add    $0x8,%rsp
    125a:	5b                   	pop    %rbx
    125b:	5d                   	pop    %rbp
    125c:	41 5c                	pop    %r12
    125e:	41 5d                	pop    %r13
    1260:	41 5e                	pop    %r14
    1262:	41 5f                	pop    %r15
    1264:	c3                   	ret    
    1265:	66 66 2e 0f 1f 84 00 	data16 cs nopw 0x0(%rax,%rax,1)
    126c:	00 00 00 00 

0000000000001270 <__libc_csu_fini>:
    1270:	f3 0f 1e fa          	endbr64 
    1274:	c3                   	ret    

Disassembly of section .fini:

0000000000001278 <_fini>:
    1278:	f3 0f 1e fa          	endbr64 
    127c:	48 83 ec 08          	sub    $0x8,%rsp
    1280:	48 83 c4 08          	add    $0x8,%rsp
    1284:	c3                   	ret    
