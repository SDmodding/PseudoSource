// File Line: 36
// RVA: 0x1075F0
void __fastcall SSParameterBase::~SSParameterBase(SSParameterBase *this)
{
  this->vfptr = (SSParameterBaseVtbl *)&SSParameterBase::`vftable';
}

// File Line: 59
// RVA: 0x116960
void __fastcall SSParameterBase::from_binary_new(const void **binary_pp)
{
  const void **v1; // rsi
  unsigned __int8 v2; // bl
  int v3; // edi
  unsigned __int8 v4; // bl
  SSGroupParam *v5; // rax
  SSUnaryParam *v6; // rax

  v1 = binary_pp;
  v2 = *(_BYTE *)*binary_pp;
  *binary_pp = (char *)*binary_pp + 1;
  v3 = v2 & 3;
  v4 = v2 >> 2;
  if ( v3 == 3 )
  {
    v5 = (SSGroupParam *)AMemory::c_malloc_func(0x28ui64, "SSGroupParam");
    if ( v5 )
      SSGroupParam::SSGroupParam(v5, v4, v1);
  }
  else
  {
    v6 = (SSUnaryParam *)AMemory::c_malloc_func(0x20ui64, "SSUnaryParam");
    if ( v6 )
      SSUnaryParam::SSUnaryParam(v6, (eSSParameter)v3, v4, v1);
  }
}

