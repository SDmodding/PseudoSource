// File Line: 47
// RVA: 0x1EECA0
void __fastcall UFG::qPropertySet::operator delete(void *ptr, unsigned __int64 size)
{
  UFG::qMemoryPool::Free(&gPropertySetMemoryPool, ptr);
}

// File Line: 87
// RVA: 0x1FB280
void __fastcall UFG::qPropertyList::ReleaseRef(UFG::qPropertyList *this)
{
  UFG::qPropertyList *v1; // rbx

  if ( this )
  {
    v1 = this;
    UFG::qPropertyList::~qPropertyList(this);
    UFG::qMemoryPool::Free(&gPropertySetMemoryPool, v1);
  }
}

// File Line: 138
// RVA: 0x642D0
UFG::qPropertySet *__fastcall UFG::qPropertyList::Get<UFG::qPropertySet>(UFG::qPropertyList *this, unsigned int index)
{
  char *v2; // rax
  UFG::qPropertySet *result; // rax

  v2 = UFG::qPropertyList::GetValuePtr(this, 0x1Au, index);
  if ( v2 && *(_QWORD *)v2 )
    result = (UFG::qPropertySet *)&v2[*(_QWORD *)v2];
  else
    result = 0i64;
  return result;
}

// File Line: 151
// RVA: 0x1E9DE0
UFG::qPropertyList *__fastcall UFG::qPropertyList::Get<UFG::qPropertyList>(UFG::qPropertyList *this, unsigned int index)
{
  unsigned int v2; // esi
  UFG::qPropertyList *v3; // rdi
  UFG::qPropertyType *v4; // rbx
  UFG::qOffset64<char const *> *v5; // rcx
  UFG::qPropertyList *result; // rax

  v2 = index;
  v3 = this;
  if ( this->mTypeUID == 25
    && index < this->mNumElements
    && (v4 = UFG::qPropertyType::Get(0x19u),
        (v5 = (UFG::qOffset64<char const *> *)&UFG::qOffset64<unsigned char *>::Get(&v3->mValues, 0i64)[v2 * ((v4->Alignment + v4->mByteSize - 1) & ~(v4->Alignment - 1))]) != 0i64) )
  {
    result = (UFG::qPropertyList *)UFG::qOffset64<char const *>::Get(v5, 0i64);
  }
  else
  {
    result = 0i64;
  }
  return result;
}

