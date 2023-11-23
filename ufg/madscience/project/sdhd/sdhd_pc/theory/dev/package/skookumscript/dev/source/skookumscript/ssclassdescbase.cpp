// File Line: 93
// RVA: 0x116A00
SSClass *__fastcall SSClassDescBase::from_binary_ref(eSSClassType class_type, const void **binary_pp)
{
  int v2; // ecx
  int v3; // ecx
  int v4; // ecx
  ASymbol *v6; // rax
  SSClass *v7; // rax
  ASymbol *v8; // rax
  ASymbol result; // [rsp+30h] [rbp+8h] BYREF

  if ( class_type )
  {
    v2 = class_type - 1;
    if ( v2 )
    {
      v3 = v2 - 1;
      if ( v3 )
      {
        v4 = v3 - 1;
        if ( v4 )
        {
          if ( v4 == 1 )
            return (SSClass *)SSClassUnion::from_binary_ref(binary_pp);
          else
            return 0i64;
        }
        else
        {
          return (SSClass *)SSInvokableClass::from_binary_ref(binary_pp);
        }
      }
      else
      {
        return (SSClass *)SSTypedClass::from_binary_ref(binary_pp);
      }
    }
    else
    {
      v6 = ASymbol::create_from_binary(&result, binary_pp);
      v7 = SSBrain::get_class(v6);
      return (SSClass *)v7->vfptr->get_metaclass(v7);
    }
  }
  else
  {
    v8 = ASymbol::create_from_binary(&result, binary_pp);
    return SSBrain::get_class(v8);
  }
}

// File Line: 132
// RVA: 0x116D20
SSClass *__fastcall SSClassDescBase::from_binary_ref_typed(const void **binary_pp)
{
  char *v1; // rax
  eSSClassType v3; // ecx

  v1 = (char *)*binary_pp;
  v3 = *(unsigned __int8 *)*binary_pp;
  *binary_pp = v1 + 1;
  return SSClassDescBase::from_binary_ref(v3, binary_pp);
}

// File Line: 171
// RVA: 0x112460
int __fastcall SSClassDescBase::compare(SSClassDescBase *this, SSClassDescBase *type)
{
  __int64 v2; // rbx
  SSClassDescBase *v3; // rdi
  SSClassDescBase *v4; // rsi
  int result; // eax
  int v6; // ebx
  eSSClassType v7; // eax
  int v8; // edx
  int v9; // ebx
  int v10; // ebx
  SSClassDescBaseVtbl *v11; // rax
  SSClassDescBaseVtbl *v12; // rcx
  unsigned int vfptr; // edx
  unsigned int v14; // r8d
  int v15; // ecx
  __int64 v16; // [rsp+30h] [rbp+8h]

  while ( 1 )
  {
    v3 = type;
    v4 = this;
    if ( this == type )
      return 0;
    v16 = v2;
    v6 = ((__int64 (*)(void))this->vfptr->get_class_type)();
    v7 = v3->vfptr->get_class_type(v3);
    v8 = v6 - v7;
    if ( v6 != v7 )
      goto LABEL_19;
    if ( !v6 )
    {
      vfptr = (unsigned int)v4[1].vfptr;
      v14 = (unsigned int)v3[1].vfptr;
      if ( vfptr == v14 )
        return 0;
      goto LABEL_16;
    }
    v9 = v6 - 1;
    if ( !v9 )
      break;
    v10 = v9 - 1;
    if ( v10 )
    {
      if ( v10 == 2 )
        return SSClassUnion::compare((SSClassUnion *)v4, (SSClassUnion *)v3);
LABEL_19:
      v15 = -1;
      if ( v8 >= 0 )
        return 1;
      return v15;
    }
    v11 = v4[2].vfptr;
    v12 = v3[2].vfptr;
    if ( v11 != v12 )
      goto LABEL_12;
    type = (SSClassDescBase *)v3[3].vfptr;
    this = (SSClassDescBase *)v4[3].vfptr;
    v2 = v16;
  }
  v12 = v3[7].vfptr;
  v11 = v4[7].vfptr;
LABEL_12:
  vfptr = *(_DWORD *)v11->gap8;
  v14 = *(_DWORD *)v12->gap8;
  if ( vfptr == v14 )
    return 0;
LABEL_16:
  result = 1;
  if ( vfptr < v14 )
    return -1;
  return result;
}

// File Line: 210
// RVA: 0x11F180
bool __fastcall SSClassDescBase::is_method_registered(SSClassDescBase *this, ASymbol *method_name)
{
  SSMethodBase *v2; // rax

  v2 = this->vfptr->get_method(this, method_name);
  return v2 && !v2->vfptr->is_placeholder(v2);
}

