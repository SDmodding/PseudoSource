// File Line: 83
// RVA: 0xA3A4D0
LPVOID __fastcall UFG::qSystemAlloc(unsigned __int64 size)
{
  return VirtualAlloc(0i64, size, 0x103000u, 4u);
}

// File Line: 89
// RVA: 0xA3A4F0
void __fastcall UFG::qSystemFree(void *memory)
{
  VirtualFree(memory, 0i64, 0x8000u);
}

// File Line: 120
// RVA: 0xA3A500
LPVOID __fastcall UFG::qVirtualAlloc(unsigned __int64 size)
{
  return VirtualAlloc(0i64, size, 0x2000u, 1u);
}

// File Line: 135
// RVA: 0xA3A520
LPVOID __fastcall UFG::qVirtualCommit(void *memory, unsigned __int64 size, UFG::qVirtualAccess access)
{
  DWORD v4; // er9

  if ( access == 1 )
    return VirtualAlloc(memory, size, 0x1000u, 2u);
  v4 = 1;
  if ( access == 2 )
    v4 = 4;
  return VirtualAlloc(memory, size, 0x1000u, v4);
}

// File Line: 144
// RVA: 0xA3A560
void __fastcall UFG::qVirtualDecommit(void *memory, unsigned __int64 size)
{
  VirtualFree(memory, size, 0x4000u);
}

// File Line: 154
// RVA: 0xA3A570
signed __int64 __fastcall UFG::qVirtualQuery(const void *memory, UFG::qBasicMemInfo *out)
{
  UFG::qBasicMemInfo *v2; // rbx
  unsigned __int8 v3; // cl
  unsigned __int8 v4; // dl
  unsigned int v5; // eax
  unsigned int v6; // eax
  int v7; // eax
  unsigned int v8; // eax
  signed __int64 result; // rax
  _MEMORY_BASIC_INFORMATION Buffer; // [rsp+20h] [rbp-38h]

  v2 = out;
  if ( (unsigned int)VirtualQuery(memory, &Buffer, 0x30ui64) != 48 )
    goto LABEL_20;
  v3 = Buffer.Protect;
  if ( v2 )
  {
    v4 = Buffer.AllocationProtect;
    v2->mpBaseAddress = Buffer.BaseAddress;
    v2->mpAllocationBase = Buffer.AllocationBase;
    if ( v4 & 2 )
      v5 = 1;
    else
      v5 = ((unsigned int)v4 >> 1) & 2;
    v2->mVirtualAccessAtAllocation = v5;
    v2->mRegionSize = Buffer.RegionSize;
    v6 = Buffer.State;
    if ( _bittest((const signed int *)&v6, 0xCu) )
      v7 = 0;
    else
      v7 = !_bittest((const signed int *)&v6, 0x10u) + 1;
    v2->mVirtualStateCurrent = v7;
    if ( v3 & 2 )
      v8 = 1;
    else
      v8 = ((unsigned int)v3 >> 1) & 2;
    v2->mVirtualAccessCurrent = v8;
    v2->mVirtualRegionType = 0;
  }
  if ( v3 & 4 )
    return 2i64;
  if ( v3 & 2 )
    result = 1i64;
  else
LABEL_20:
    result = 0i64;
  return result;
}

