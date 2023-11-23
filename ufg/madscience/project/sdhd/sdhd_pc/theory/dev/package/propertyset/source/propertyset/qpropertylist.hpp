// File Line: 47
// RVA: 0x1EECA0
void __fastcall UFG::qPropertySet::operator delete(char *ptr, unsigned __int64 size)
{
  UFG::qMemoryPool::Free(&gPropertySetMemoryPool, ptr);
}

// File Line: 87
// RVA: 0x1FB280
void __fastcall UFG::qPropertyList::ReleaseRef(UFG::qPropertyList *this)
{
  if ( this )
  {
    UFG::qPropertyList::~qPropertyList(this);
    UFG::qMemoryPool::Free(&gPropertySetMemoryPool, (char *)this);
  }
}

// File Line: 138
// RVA: 0x642D0
UFG::qPropertySet *__fastcall UFG::qPropertyList::Get<UFG::qPropertySet>(UFG::qPropertyList *this, unsigned int index)
{
  char *ValuePtr; // rax

  ValuePtr = UFG::qPropertyList::GetValuePtr(this, 0x1Au, index);
  if ( ValuePtr && *(_QWORD *)ValuePtr )
    return (UFG::qPropertySet *)&ValuePtr[*(_QWORD *)ValuePtr];
  else
    return 0i64;
}

// File Line: 151
// RVA: 0x1E9DE0
UFG::qPropertyList *__fastcall UFG::qPropertyList::Get<UFG::qPropertyList>(
        UFG::qPropertyList *this,
        unsigned int index)
{
  UFG::qPropertyType *v4; // rbx
  UFG::qOffset64<char const *> *v5; // rcx

  if ( this->mTypeUID == 25
    && index < this->mNumElements
    && (v4 = UFG::qPropertyType::Get(0x19u),
        (v5 = (UFG::qOffset64<char const *> *)&UFG::qOffset64<unsigned char *>::Get(&this->mValues, 0i64)[index * ((v4->Alignment + v4->mByteSize - 1) & ~(v4->Alignment - 1))]) != 0i64) )
  {
    return (UFG::qPropertyList *)UFG::qOffset64<char const *>::Get(v5, 0i64);
  }
  else
  {
    return 0i64;
  }
}

