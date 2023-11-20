// File Line: 116
// RVA: 0x5B7AB0
void __fastcall UEL::Value::Type::Type(UEL::Value::Type *this)
{
  this->mBaseType.mValue = 0;
  this->mDetailedType = UFG::gNullQSymbol;
}

// File Line: 117
// RVA: 0x192F00
void __fastcall UEL::Value::Type::Type(UEL::Value::Type *this, UEL::Value::BaseType eBaseType)
{
  this->mBaseType.mValue = eBaseType;
  this->mDetailedType = UFG::gNullQSymbol;
}

// File Line: 118
// RVA: 0x5B7AA0
void __fastcall UEL::Value::Type::Type(UEL::Value::Type *this, UEL::Value::BaseType eBaseType, __int64 detailedType)
{
  this->mBaseType.mValue = eBaseType;
  this->mDetailedType.mUID = *(_DWORD *)detailedType;
}

// File Line: 145
// RVA: 0x24E560
void __fastcall UEL::Value::Value(UEL::Value *this)
{
  this->type.mBaseType.mValue = 0;
  this->type.mDetailedType = UFG::gNullQSymbol;
}

// File Line: 154
// RVA: 0x24E720
UEL::Value *__fastcall UEL::Value::operator=(UEL::Value *this, UEL::Value *o)
{
  UEL::Value *result; // rax

  this->type.mBaseType.mValue = o->type.mBaseType.mValue;
  this->type.mDetailedType.mUID = o->type.mDetailedType.mUID;
  switch ( o->type.mBaseType.mValue )
  {
    case 1u:
    case 3u:
    case 8u:
    case 9u:
    case 0xAu:
      this->integer = o->integer;
      goto LABEL_6;
    case 2u:
    case 4u:
    case 6u:
      this->qSymbol_mUID = o->qSymbol_mUID;
      result = this;
      break;
    case 5u:
      this->boolean = o->boolean;
      result = this;
      break;
    case 7u:
      this->qSymbol_mUID = o->qSymbol_mUID;
      this->qVector_y = o->qVector_y;
      this->qVector_z = o->qVector_z;
      this->qVector_w = o->qVector_w;
      result = this;
      break;
    default:
LABEL_6:
      result = this;
      break;
  }
  return result;
}

// File Line: 402
// RVA: 0x253640
void __fastcall UEL::Value::SetString(UEL::Value *this, const char *str)
{
  unsigned int v2; // eax
  UEL::Value *v3; // r14
  __int64 v4; // rbp
  unsigned int v5; // edi
  const char *v6; // r15
  unsigned int v7; // ebx
  unsigned __int64 v8; // rax
  UFG::allocator::free_link *v9; // rax
  char **v10; // r9
  char **v11; // rsi
  signed __int64 v12; // r8
  signed __int64 v13; // rdx
  __int64 *v14; // rsi
  int v15; // eax
  unsigned __int64 v16; // rbx
  UFG::allocator::free_link *v17; // rax

  v2 = UFG::gNullQSymbol.mUID;
  v3 = this;
  this->type.mBaseType.mValue = 3;
  this->type.mDetailedType.mUID = v2;
  v4 = UEL::Value::msStringTable.size;
  v5 = UEL::Value::msStringTable.size + 1;
  v6 = str;
  if ( UEL::Value::msStringTable.size + 1 <= UEL::Value::msStringTable.capacity )
    goto LABEL_23;
  if ( UEL::Value::msStringTable.capacity )
    v7 = 2 * UEL::Value::msStringTable.capacity;
  else
    v7 = 1;
  for ( ; v7 < v5; v7 *= 2 )
    ;
  if ( v7 <= 2 )
    v7 = 2;
  if ( v7 - v5 > 0x10000 )
    v7 = UEL::Value::msStringTable.size + 65537;
  if ( v7 == (_DWORD)v4 )
  {
LABEL_23:
    v11 = UEL::Value::msStringTable.p;
  }
  else
  {
    v8 = 8i64 * v7;
    if ( !is_mul_ok(v7, 8ui64) )
      v8 = -1i64;
    v9 = UFG::qMalloc(v8, "qArray.Add", 0i64);
    v10 = UEL::Value::msStringTable.p;
    v11 = (char **)v9;
    if ( UEL::Value::msStringTable.p )
    {
      v12 = 0i64;
      if ( UEL::Value::msStringTable.size )
      {
        do
        {
          v13 = v12;
          v12 = (unsigned int)(v12 + 1);
          v9[v13].mNext = (UFG::allocator::free_link *)v10[v13];
          v10 = UEL::Value::msStringTable.p;
        }
        while ( (unsigned int)v12 < UEL::Value::msStringTable.size );
      }
      operator delete[](v10);
    }
    UEL::Value::msStringTable.p = v11;
    UEL::Value::msStringTable.capacity = v7;
  }
  UEL::Value::msStringTable.size = v5;
  v14 = (__int64 *)&v11[v4];
  v15 = UFG::qStringLength(v6);
  v16 = (unsigned int)(v15 + 1);
  v17 = UFG::qMalloc(v16, "UEL::Value::msStringTable", 0i64);
  *v14 = (__int64)v17;
  UFG::qMemCopy(v17, v6, v16);
  *(_BYTE *)(v16 + *v14) = 0;
  v3->integer = *v14;
}

// File Line: 493
// RVA: 0x5B78F0
void __fastcall UEL::InvocableBindingEntry::InvocableBindingEntry(UEL::InvocableBindingEntry *this, __int64 name, unsigned int functionTableIndex, UEL::Value::Type returnType, UEL::Value::Type arg1, UEL::Value::Type arg2, UEL::Value::Type arg3, UEL::Value::Type arg4, UEL::Value::Type arg5, UEL::Value::Type arg6, UEL::Value::Type arg7, UEL::Value::Type arg8)
{
  UEL::Value::Type v12; // r14
  unsigned int v13; // esi
  UEL::InvocableBindingEntry *v14; // r15
  int v15; // ebx
  unsigned int v16; // eax
  __int64 v17; // rcx
  bool v18; // al

  v12 = returnType;
  v13 = functionTableIndex;
  v14 = this;
  v15 = 0;
  v16 = *(_DWORD *)name;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v16;
  this->name.mUID = -1;
  `eh vector constructor iterator(this->args, 8ui64, 8, (void (__fastcall *)(void *))UEL::Value::Type::Type);
  v14->functionTableIndex = v13;
  v14->returnType.mBaseType.mValue = **(_WORD **)&v12;
  v14->returnType.mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&v12 + 4i64);
  v14->args[0].mBaseType.mValue = **(_WORD **)&arg1;
  v14->args[0].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg1 + 4i64);
  v14->args[1].mBaseType.mValue = **(_WORD **)&arg2;
  v14->args[1].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg2 + 4i64);
  v14->args[2].mBaseType.mValue = **(_WORD **)&arg3;
  v14->args[2].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg3 + 4i64);
  v14->args[3].mBaseType.mValue = **(_WORD **)&arg4;
  v14->args[3].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg4 + 4i64);
  v14->args[4].mBaseType.mValue = **(_WORD **)&arg5;
  v14->args[4].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg5 + 4i64);
  v14->args[5].mBaseType.mValue = **(_WORD **)&arg6;
  v14->args[5].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg6 + 4i64);
  v14->args[6].mBaseType.mValue = **(_WORD **)&arg7;
  v14->args[6].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg7 + 4i64);
  v14->args[7].mBaseType.mValue = **(_WORD **)&arg8;
  v14->args[7].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg8 + 4i64);
  for ( v14->numArgs = 0; ; v14->numArgs = v17 + 1 )
  {
    v18 = ((v15 |= 1u, v17 = (unsigned __int8)v14->numArgs, 0 != v14->args[v17].mBaseType.mValue)
        || UFG::gNullQSymbol.mUID != v14->args[v17].mDetailedType.mUID)
       && (unsigned __int8)v17 < 8u;
    if ( v15 & 1 )
      v15 &= 0xFFFFFFFE;
    if ( !v18 )
      break;
  }
}

// File Line: 526
// RVA: 0x24E3E0
void __fastcall UEL::ParameterBindingEntry::ParameterBindingEntry(UEL::ParameterBindingEntry *this, __int64 name, UEL::Value::Type type, UEL::Value::Type alwaysReturns, bool needsCall, unsigned int offset, UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *parameterNameToDataMap, bool ownsParameterNameToDataMap)
{
  unsigned int v8; // eax

  v8 = *(_DWORD *)name;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v8;
  this->name.mUID = *(_DWORD *)name;
  this->type.mBaseType.mValue = **(_WORD **)&type;
  this->type.mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&type + 4i64);
  this->alwaysReturns.mBaseType.mValue = **(_WORD **)&alwaysReturns;
  this->alwaysReturns.mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&alwaysReturns + 4i64);
  this->needsCall = needsCall;
  this->offset = offset;
  this->parameterNameToDataMap = parameterNameToDataMap;
  this->ownsParameterNameToDataMap = ownsParameterNameToDataMap;
}

// File Line: 530
// RVA: 0x24E6F0
void __fastcall UEL::ParameterBindingEntry::~ParameterBindingEntry(UEL::ParameterBindingEntry *this)
{
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *v1; // rbx

  v1 = this->parameterNameToDataMap;
  if ( v1 )
  {
    if ( this->ownsParameterNameToDataMap )
    {
      UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::~qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>(this->parameterNameToDataMap);
      operator delete[](v1);
    }
  }
}

// File Line: 643
// RVA: 0x1933A0
void __fastcall UEL::Expression::~Expression(UEL::Expression *this)
{
  this->vfptr = (UEL::ExpressionVtbl *)&UEL::Expression::`vftable;
}

// File Line: 652
// RVA: 0x251E60
UEL::Value::Type *__fastcall UEL::Expression::GetValueType(UEL::Expression *this, UEL::Value::Type *result)
{
  result->mBaseType.mValue = this->mValueType.mBaseType.mValue;
  result->mDetailedType.mUID = this->mValueType.mDetailedType.mUID;
  return result;
}

