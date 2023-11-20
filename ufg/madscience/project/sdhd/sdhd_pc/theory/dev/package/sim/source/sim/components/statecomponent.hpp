// File Line: 61
// RVA: 0xFB7B0
void __fastcall UFG::StateComponentI<UFG::SimComponent>::~StateComponentI<UFG::SimComponent>(UFG::StateComponentI<UFG::SimComponent> *this)
{
  UFG::StateComponentI<UFG::SimComponent> *v1; // rbx

  v1 = this;
  this->vfptr = (UFG::qSafePointerNode<UFG::SimComponent>Vtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::SimComponent};
  this->vfptr = (UFG::StateInterfaceVtbl *)&UFG::StateComponentI<UFG::SimComponent>::`vftable{for `UFG::StateInterface};
  if ( (LOBYTE(this->m_Flags) >> 2) & 1 )
  {
    this->m_Flags |= 2u;
    ((void (__cdecl *)(UFG::StateComponentI<UFG::SimComponent> *))this->vfptr[16].__vecDelDtor)(this);
    v1->m_Flags &= 0xFFFBu;
  }
  UFG::SimComponent::~SimComponent((UFG::SimComponent *)&v1->vfptr);
}

// File Line: 67
// RVA: 0xFFE80
UFG::StateInterface *__fastcall UFG::StateComponentI<UFG::SimComponent>::GetStateInterface(UFG::StateComponentI<UFG::SimComponent> *this)
{
  UFG::StateInterface *result; // rax

  if ( this )
    result = (UFG::StateInterface *)&this->vfptr;
  else
    result = 0i64;
  return result;
}

// File Line: 73
// RVA: 0xFD010
__int64 __fastcall UFG::StateComponentI<UFG::SimComponent>::Enter(UFG::StateComponentI<UFG::SimComponent> *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v1; // rax
  UFG::StateComponentI<UFG::SimComponent> *v2; // rbx
  __int64 result; // rax

  v1 = this[-1].m_SafePointerList.mNode.mNext;
  v2 = this;
  HIDWORD(this->m_SafePointerList.mNode.mPrev) = 0;
  result = ((__int64 (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))v1[7].mPrev)(&this[-1].m_SafePointerList.mNode.mNext);
  if ( (_BYTE)result )
  {
    LOWORD(v2[-1].m_BoundComponentHandles.mNode.mPrev) |= 4u;
    LOWORD(v2[-1].m_BoundComponentHandles.mNode.mPrev) &= 0xFFFDu;
  }
  return result;
}

// File Line: 87
// RVA: 0x102B00
void __fastcall UFG::StateComponentI<UFG::SimComponent>::Update(UFG::StateComponentI<UFG::SimComponent> *this, float fDeltaT)
{
  UFG::StateComponentI<UFG::SimComponent> *v2; // rbx

  v2 = this;
  if ( !((LOBYTE(this[-1].m_BoundComponentHandles.mNode.mPrev) >> 2) & 1) && LOBYTE(this->m_SafePointerList.mNode.mPrev) )
    ((void (*)(void))this->vfptr->__vecDelDtor)();
  ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))v2[-1].m_SafePointerList.mNode.mNext[7].mNext)(&v2[-1].m_SafePointerList.mNode.mNext);
  *((float *)&v2->m_SafePointerList.mNode.mPrev + 1) = fDeltaT + *((float *)&v2->m_SafePointerList.mNode.mPrev + 1);
}

// File Line: 99
// RVA: 0xFD050
void __fastcall UFG::StateComponentI<UFG::SimComponent>::Exit(UFG::StateComponentI<UFG::SimComponent> *this)
{
  UFG::StateComponentI<UFG::SimComponent> *v1; // rbx

  LOWORD(this[-1].m_BoundComponentHandles.mNode.mPrev) |= 2u;
  v1 = this;
  ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))this[-1].m_SafePointerList.mNode.mNext[8].mPrev)(&this[-1].m_SafePointerList.mNode.mNext);
  LOWORD(v1[-1].m_BoundComponentHandles.mNode.mPrev) &= 0xFFFBu;
}

// File Line: 110
// RVA: 0x102430
void __fastcall UFG::StateComponentI<UFG::SimComponent>::Reset(UFG::StateComponentI<UFG::SimComponent> *this)
{
  UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> *v1; // rax

  v1 = this[-1].m_SafePointerList.mNode.mNext;
  HIDWORD(this->m_SafePointerList.mNode.mPrev) = 0;
  ((void (__fastcall *)(UFG::qNode<UFG::qSafePointerBase<UFG::SimComponent>,UFG::qSafePointerNodeList> **))v1[8].mNext)(&this[-1].m_SafePointerList.mNode.mNext);
}

// File Line: 122
// RVA: 0x1004C0
__int64 __fastcall UFG::StateComponentI<UFG::SimComponent>::IsActive(UFG::StateComponentI<UFG::SimComponent> *this)
{
  return ((unsigned int)LOWORD(this[-1].m_BoundComponentHandles.mNode.mPrev) >> 2) & 1;
}

// File Line: 143
// RVA: 0x101180
void __fastcall UFG::StateComponentI<UFG::SimComponent>::OnDetach(UFG::StateComponentI<UFG::SimComponent> *this)
{
  UFG::StateInterface *v1; // rbx

  v1 = (UFG::StateInterface *)&this->vfptr;
  if ( this->vfptr->IsActive((UFG::StateInterface *)&this->vfptr) )
    v1->vfptr->Exit(v1);
}

