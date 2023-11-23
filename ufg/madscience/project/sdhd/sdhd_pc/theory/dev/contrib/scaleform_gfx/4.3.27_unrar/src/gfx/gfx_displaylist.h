// File Line: 148
// RVA: 0x6D1F80
void __fastcall Scaleform::GFx::DisplayList::MemberVisitor::~MemberVisitor(
        Scaleform::GFx::DisplayList::MemberVisitor *this)
{
  this->vfptr = (Scaleform::GFx::DisplayList::MemberVisitorVtbl *)&Scaleform::GFx::DisplayList::MemberVisitor::`vftable;
}

// File Line: 170
// RVA: 0x906FC0
void __fastcall Scaleform::GFx::DisplayList::DepthToIndexContainer::SetElement(
        Scaleform::GFx::DisplayList::DepthToIndexContainer *this,
        unsigned __int64 index,
        unsigned int depth,
        unsigned int mappedIndex)
{
  unsigned __int64 Size; // rax
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  Scaleform::GFx::DisplayList::DepthToIndexMapElem *Data; // rax
  unsigned __int64 *v9; // rcx
  unsigned __int64 v10; // [rsp+30h] [rbp+8h]

  Size = this->Array.Data.Size;
  v10 = __PAIR64__(mappedIndex, depth);
  if ( index < Size )
  {
    this->Array.Data.Data[index] = (Scaleform::GFx::DisplayList::DepthToIndexMapElem)__PAIR64__(mappedIndex, depth);
    return;
  }
  v6 = Size + 1;
  if ( Size + 1 >= Size )
  {
    if ( v6 <= this->Array.Data.Policy.Capacity )
      goto LABEL_9;
    v7 = v6 + (v6 >> 2);
  }
  else
  {
    if ( v6 >= this->Array.Data.Policy.Capacity >> 1 )
      goto LABEL_9;
    v7 = Size + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)this,
    this,
    v7);
LABEL_9:
  Data = this->Array.Data.Data;
  this->Array.Data.Size = v6;
  v9 = (unsigned __int64 *)&Data[v6 - 1];
  if ( v9 )
    *v9 = v10;
}

// File Line: 235
// RVA: 0x8A3BB0
void __fastcall Scaleform::GFx::DisplayList::~DisplayList(Scaleform::GFx::DisplayList *this)
{
  Scaleform::GFx::DisplayList::DepthToIndexContainer *DepthToIndexMap; // rdi

  DepthToIndexMap = this->DepthToIndexMap;
  if ( DepthToIndexMap )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, DepthToIndexMap->Array.Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, DepthToIndexMap);
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>(&this->DisplayObjectArray.Data);
}

