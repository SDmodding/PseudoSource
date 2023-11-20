// File Line: 148
// RVA: 0x6D1F80
void __fastcall Scaleform::GFx::DisplayList::MemberVisitor::~MemberVisitor(Scaleform::GFx::DisplayList::MemberVisitor *this)
{
  this->vfptr = (Scaleform::GFx::DisplayList::MemberVisitorVtbl *)&Scaleform::GFx::DisplayList::MemberVisitor::`vftable;
}

// File Line: 170
// RVA: 0x906FC0
void __fastcall Scaleform::GFx::DisplayList::DepthToIndexContainer::SetElement(Scaleform::GFx::DisplayList::DepthToIndexContainer *this, unsigned __int64 index, int depth, unsigned int mappedIndex)
{
  unsigned __int64 v4; // rax
  Scaleform::GFx::DisplayList::DepthToIndexContainer *v5; // rbx
  unsigned __int64 v6; // rdi
  unsigned __int64 v7; // r8
  Scaleform::GFx::DisplayList::DepthToIndexMapElem *v8; // rax
  unsigned __int64 *v9; // rcx
  unsigned __int64 v10; // [rsp+30h] [rbp+8h]

  v4 = this->Array.Data.Size;
  v5 = this;
  v10 = __PAIR__(mappedIndex, depth);
  if ( index < v4 )
  {
    this->Array.Data.Data[index] = (Scaleform::GFx::DisplayList::DepthToIndexMapElem)__PAIR__(mappedIndex, depth);
    return;
  }
  v6 = v4 + 1;
  if ( v4 + 1 >= v4 )
  {
    if ( v6 <= this->Array.Data.Policy.Capacity )
      goto LABEL_9;
    v7 = v6 + (v6 >> 2);
  }
  else
  {
    if ( v6 >= this->Array.Data.Policy.Capacity >> 1 )
      goto LABEL_9;
    v7 = v4 + 1;
  }
  Scaleform::ArrayDataBase<Scaleform::Render::Text::LineBuffer::Line *,Scaleform::AllocatorLH<Scaleform::Render::Text::LineBuffer::Line *,2>,Scaleform::ArrayDefaultPolicy>::Reserve(
    (Scaleform::ArrayDataBase<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,Scaleform::AllocatorLH<Scaleform::Ptr<Scaleform::GFx::AS2::Object>,2>,Scaleform::ArrayDefaultPolicy> *)this,
    this,
    v7);
LABEL_9:
  v8 = v5->Array.Data.Data;
  v5->Array.Data.Size = v6;
  v9 = (unsigned __int64 *)&v8[v6 - 1];
  if ( v9 )
    *v9 = v10;
}

// File Line: 235
// RVA: 0x8A3BB0
void __fastcall Scaleform::GFx::DisplayList::~DisplayList(Scaleform::GFx::DisplayList *this)
{
  Scaleform::GFx::DisplayList *v1; // rbx
  Scaleform::GFx::DisplayList::DepthToIndexContainer *v2; // rdi

  v1 = this;
  v2 = this->DepthToIndexMap;
  if ( v2 )
  {
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2->Array.Data.Data);
    Scaleform::Memory::pGlobalHeap->vfptr->Free(Scaleform::Memory::pGlobalHeap, v2);
  }
  Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>::~ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy>((Scaleform::ArrayDataBase<Scaleform::GFx::DisplayList::DisplayEntry,Scaleform::AllocatorLH<Scaleform::GFx::DisplayList::DisplayEntry,2>,Scaleform::ArrayDefaultPolicy> *)&v1->DisplayObjectArray.Data.Data);
}

