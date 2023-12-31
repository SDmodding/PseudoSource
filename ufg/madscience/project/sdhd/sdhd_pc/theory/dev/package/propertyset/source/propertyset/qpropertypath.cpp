// File Line: 29
// RVA: 0x1ED4B0
void __fastcall UFG::qPropertyPath::qPropertyPath(UFG::qPropertyPath *this)
{
  UFG::qArray<UFG::qSymbolUC,0>::qArray<UFG::qSymbolUC,0>(&this->mPath);
}

// File Line: 38
// RVA: 0x1EED10
UFG::qPropertyPath *__fastcall UFG::qPropertyPath::operator=(UFG::qPropertyPath *this, UFG::qPropertyPath *other)
{
  UFG::qArray<enum DNA::PropertyState::Enum,0>::Clone(&other->mPath, &this->mPath);
  return this;
}

// File Line: 44
// RVA: 0x1F23E0
// attributes: thunk
void __fastcall UFG::qPropertyPath::Clear(UFG::qPropertyPath *this)
{
  UFG::qArray<UFG::PartRequest *,0>::~qArray<UFG::PartRequest *,0>((UFG::qArray<ActiveMultiMorphTarget,0> *)this);
}

// File Line: 49
// RVA: 0x1FA9A0
void __fastcall UFG::qPropertyPath::Push(UFG::qPropertyPath *this, unsigned int arrayIndex)
{
  unsigned int item; // [rsp+38h] [rbp+10h] BYREF

  item = arrayIndex;
  UFG::qArray<int,0>::Add(&this->mPath, &item, "qArray.Add");
}

// File Line: 54
// RVA: 0x1FA980
void __fastcall UFG::qPropertyPath::Push(UFG::qPropertyPath *this, UFG::qSymbol *propertyName)
{
  unsigned int item; // [rsp+30h] [rbp+8h] BYREF

  item = propertyName->mUID;
  UFG::qArray<int,0>::Add(&this->mPath, &item, "qArray.Add");
}

// File Line: 59
// RVA: 0x1FA4D0
void __fastcall UFG::qPropertyPath::Pop(UFG::qPropertyPath *this)
{
  int v2; // eax

  v2 = UFG::qSymbolUC::as_uint32(&this->mPath);
  UFG::qArray<unsigned long,0>::_FastDelete(&this->mPath, v2 - 1);
}

// File Line: 72
// RVA: 0x1F6EA0
__int64 __fastcall UFG::qPropertyPath::GetHash(UFG::qPropertyPath *this)
{
  unsigned int v2; // eax
  unsigned int *p; // r10
  unsigned int v4; // r8d
  unsigned int v5; // r9d
  _DWORD *v6; // r10
  char v7; // cl
  int v8; // edx

  v2 = UFG::qSymbolUC::as_uint32(&this->mPath);
  if ( !v2 )
    return 0i64;
  p = this->mPath.p;
  v4 = 1;
  v5 = *p;
  if ( v2 > 1 )
  {
    v6 = p + 1;
    do
    {
      v7 = v4++;
      v8 = *v6++ + 1;
      v5 ^= __ROL4__(v8, v7 & 0x1F);
    }
    while ( v4 < v2 );
  }
  return v5;
}

