// File Line: 61
// RVA: 0xFB7B0
void __fastcall UFG::StateComponentI<UFG::SimComponent>::~StateComponentI<UFG::SimComponent>(
        UFG::StateComponentI<UFG::SimComponent> *this)
{
  this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  this->UFG::StateInterface::vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  if ( (this->m_Flags & 4) != 0 )
  {
    this->m_Flags |= 2u;
    ((void (__fastcall *)(UFG::StateComponentI<UFG::SimComponent> *))this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr[16].__vecDelDtor)(this);
    this->m_Flags &= ~4u;
  }
  UFG::SimComponent::~SimComponent(this);
}

// File Line: 67
// RVA: 0xFFE80
UFG::StateInterface *__fastcall UFG::StateComponentI<UFG::SimComponent>::GetStateInterface(
        UFG::StateComponentI<UFG::SimComponent> *this)
{
  if ( this )
    return &this->UFG::StateInterface;
  else
    return 0i64;
}

// File Line: 73
// RVA: 0xFD010
__int64 __fastcall UFG::StateComponentI<UFG::SimComponent>::Enter(UFG::StateComponentI<UFG::SimComponent> *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax
  __int64 result; // rax

  mNext = this[-1].m_SafePointerList.mNode.mNext;
  HIDWORD(this->m_SafePointerList.mNode.mPrev) = 0;
  result = ((__int64 (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))mNext[7].mPrev)(&this[-1].m_SafePointerList.mNode.mNext);
  if ( (_BYTE)result )
  {
    LOWORD(this[-1].m_BoundComponentHandles.mNode.mPrev) |= 4u;
    LOWORD(this[-1].m_BoundComponentHandles.mNode.mPrev) &= ~2u;
  }
  return result;
}

// File Line: 87
// RVA: 0x102B00
void __fastcall UFG::StateComponentI<UFG::SimComponent>::Update(
        UFG::StateComponentI<UFG::SimComponent> *this,
        float fDeltaT)
{
  if ( ((__int64)this[-1].m_BoundComponentHandles.mNode.mPrev & 4) == 0 && LOBYTE(this->m_SafePointerList.mNode.mPrev) )
    ((void (__fastcall *)(UFG::StateComponentI<UFG::SimComponent> *))this->UFG::SimComponent::UFG::qSafePointerNode<UFG::SimComponent>::vfptr->__vecDelDtor)(this);
  ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))this[-1].m_SafePointerList.mNode.mNext[7].mNext)(&this[-1].m_SafePointerList.mNode.mNext);
  *((float *)&this->m_SafePointerList.mNode.mPrev + 1) = fDeltaT + *((float *)&this->m_SafePointerList.mNode.mPrev + 1);
}

// File Line: 99
// RVA: 0xFD050
void __fastcall UFG::StateComponentI<UFG::SimComponent>::Exit(UFG::StateComponentI<UFG::SimComponent> *this)
{
  LOWORD(this[-1].m_BoundComponentHandles.mNode.mPrev) |= 2u;
  ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))this[-1].m_SafePointerList.mNode.mNext[8].mPrev)(&this[-1].m_SafePointerList.mNode.mNext);
  LOWORD(this[-1].m_BoundComponentHandles.mNode.mPrev) &= ~4u;
}

// File Line: 110
// RVA: 0x102430
void __fastcall UFG::StateComponentI<UFG::SimComponent>::Reset(UFG::StateComponentI<UFG::SimComponent> *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *mNext; // rax

  mNext = this[-1].m_SafePointerList.mNode.mNext;
  HIDWORD(this->m_SafePointerList.mNode.mPrev) = 0;
  ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))mNext[8].mNext)(&this[-1].m_SafePointerList.mNode.mNext);
}

// File Line: 122
// RVA: 0x1004C0
__int64 __fastcall UFG::StateComponentI<UFG::SimComponent>::IsActive(UFG::StateComponentI<UFG::SimComponent> *this)
{
  return (LOWORD(this[-1].m_BoundComponentHandles.mNode.mPrev) >> 2) & 1;
}

// File Line: 143
// RVA: 0x101180
void __fastcall UFG::StateComponentI<UFG::SimComponent>::OnDetach(UFG::StateComponentI<UFG::SimComponent> *this)
{
  UFG::StateInterface *v1; // rbx

  v1 = &this->UFG::StateInterface;
  if ( this->UFG::StateInterface::vfptr->IsActive(&this->UFG::StateInterface) )
    v1->vfptr->Exit(v1);
}

