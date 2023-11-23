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
void __fastcall UEL::Value::Type::Type(
        UEL::Value::Type *this,
        UEL::Value::BaseType eBaseType,
        unsigned int *detailedType)
{
  this->mBaseType.mValue = eBaseType;
  this->mDetailedType.mUID = *detailedType;
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
  unsigned int mUID; // eax
  __int64 size; // rbp
  unsigned int v5; // edi
  unsigned int v7; // ebx
  unsigned __int64 v8; // rax
  UFG::allocator::free_link *v9; // rax
  char **v10; // r9
  char **p; // rsi
  __int64 i; // r8
  __int64 v13; // rdx
  __int64 *v14; // rsi
  unsigned __int64 v15; // rbx
  UFG::allocator::free_link *v16; // rax

  mUID = UFG::gNullQSymbol.mUID;
  this->type.mBaseType.mValue = 3;
  this->type.mDetailedType.mUID = mUID;
  size = UEL::Value::msStringTable.size;
  v5 = UEL::Value::msStringTable.size + 1;
  if ( UEL::Value::msStringTable.size + 1 <= UEL::Value::msStringTable.capacity )
    goto LABEL_19;
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
  if ( v7 == UEL::Value::msStringTable.size )
  {
LABEL_19:
    p = UEL::Value::msStringTable.p;
  }
  else
  {
    v8 = 8i64 * v7;
    if ( !is_mul_ok(v7, 8ui64) )
      v8 = -1i64;
    v9 = UFG::qMalloc(v8, "qArray.Add", 0i64);
    v10 = UEL::Value::msStringTable.p;
    p = (char **)v9;
    if ( UEL::Value::msStringTable.p )
    {
      for ( i = 0i64; (unsigned int)i < UEL::Value::msStringTable.size; v10 = UEL::Value::msStringTable.p )
      {
        v13 = i;
        i = (unsigned int)(i + 1);
        v9[v13].mNext = (UFG::allocator::free_link *)v10[v13];
      }
      operator delete[](v10);
    }
    UEL::Value::msStringTable.p = p;
    UEL::Value::msStringTable.capacity = v7;
  }
  UEL::Value::msStringTable.size = v5;
  v14 = (__int64 *)&p[size];
  v15 = (unsigned int)UFG::qStringLength(str) + 1;
  v16 = UFG::qMalloc(v15, "UEL::Value::msStringTable", 0i64);
  *v14 = (__int64)v16;
  UFG::qMemCopy(v16, str, v15);
  *(_BYTE *)(v15 + *v14) = 0;
  this->integer = *v14;
}

// File Line: 493
// RVA: 0x5B78F0
void __fastcall UEL::InvocableBindingEntry::InvocableBindingEntry(
        UEL::InvocableBindingEntry *this,
        unsigned int *name,
        unsigned int functionTableIndex,
        UEL::Value::Type returnType,
        UEL::Value::Type arg1,
        UEL::Value::Type arg2,
        UEL::Value::Type arg3,
        UEL::Value::Type arg4,
        UEL::Value::Type arg5,
        UEL::Value::Type arg6,
        UEL::Value::Type arg7,
        UEL::Value::Type arg8)
{
  int v15; // ebx
  unsigned int v16; // eax
  __int64 numArgs; // rcx
  bool v18; // al

  v15 = 0;
  v16 = *name;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v16;
  this->name.mUID = -1;
  `eh vector constructor iterator(this->args, 8ui64, 8, (void (__fastcall *)(void *))UEL::Value::Type::Type);
  this->functionTableIndex = functionTableIndex;
  this->returnType.mBaseType.mValue = *(_WORD *)returnType.mBaseType.mValue;
  this->returnType.mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&returnType + 4i64);
  this->args[0].mBaseType.mValue = *(_WORD *)arg1.mBaseType.mValue;
  this->args[0].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg1 + 4i64);
  this->args[1].mBaseType.mValue = *(_WORD *)arg2.mBaseType.mValue;
  this->args[1].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg2 + 4i64);
  this->args[2].mBaseType.mValue = *(_WORD *)arg3.mBaseType.mValue;
  this->args[2].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg3 + 4i64);
  this->args[3].mBaseType.mValue = *(_WORD *)arg4.mBaseType.mValue;
  this->args[3].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg4 + 4i64);
  this->args[4].mBaseType.mValue = *(_WORD *)arg5.mBaseType.mValue;
  this->args[4].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg5 + 4i64);
  this->args[5].mBaseType.mValue = *(_WORD *)arg6.mBaseType.mValue;
  this->args[5].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg6 + 4i64);
  this->args[6].mBaseType.mValue = *(_WORD *)arg7.mBaseType.mValue;
  this->args[6].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg7 + 4i64);
  this->args[7].mBaseType.mValue = *(_WORD *)arg8.mBaseType.mValue;
  this->args[7].mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&arg8 + 4i64);
  for ( this->numArgs = 0; ; this->numArgs = numArgs + 1 )
  {
    v18 = ((v15 |= 1u, numArgs = (unsigned __int8)this->numArgs, this->args[numArgs].mBaseType.mValue)
        || UFG::gNullQSymbol.mUID != this->args[numArgs].mDetailedType.mUID)
       && (unsigned __int8)numArgs < 8u;
    if ( (v15 & 1) != 0 )
      v15 &= ~1u;
    if ( !v18 )
      break;
  }
}

// File Line: 526
// RVA: 0x24E3E0
void __fastcall UEL::ParameterBindingEntry::ParameterBindingEntry(
        UEL::ParameterBindingEntry *this,
        unsigned int *name,
        UEL::Value::Type type,
        UEL::Value::Type alwaysReturns,
        bool needsCall,
        unsigned int offset,
        UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *parameterNameToDataMap,
        bool ownsParameterNameToDataMap)
{
  unsigned int v8; // eax

  v8 = *name;
  this->mNode.mParent = 0i64;
  this->mNode.mChild[0] = 0i64;
  this->mNode.mChild[1] = 0i64;
  this->mNode.mUID = v8;
  this->name.mUID = *name;
  this->type.mBaseType.mValue = *(_WORD *)type.mBaseType.mValue;
  this->type.mDetailedType.mUID = *(_DWORD *)(*(_QWORD *)&type + 4i64);
  this->alwaysReturns.mBaseType.mValue = *(_WORD *)alwaysReturns.mBaseType.mValue;
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
  UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1> *parameterNameToDataMap; // rbx

  parameterNameToDataMap = this->parameterNameToDataMap;
  if ( parameterNameToDataMap )
  {
    if ( this->ownsParameterNameToDataMap )
    {
      UFG::qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>::~qTreeRB<UEL::ParameterBindingEntry,UEL::ParameterBindingEntry,1>(this->parameterNameToDataMap);
      operator delete[](parameterNameToDataMap);
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

