// File Line: 43
// RVA: 0x2633C0
UFG::ComponentIDDesc *__fastcall UFG::NavComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc *v0; // rax
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h]

  if ( !UFG::NavComponent::_DescInit )
  {
    v0 = UFG::Simulation_GetNewBaseDesc(&result);
    *(_QWORD *)&UFG::NavComponent::_TypeIDesc.mBaseTypeIndex = *(_QWORD *)&v0->mBaseTypeIndex;
    UFG::NavComponent::_TypeIDesc.mChildren = v0->mChildren;
    UFG::NavComponent::_DescInit = 1;
    UFG::NavComponent::_TypeUID = UFG::NavComponent::_TypeIDesc.mChildBitMask | (UFG::NavComponent::_TypeIDesc.mBaseTypeIndex << 25);
    UFG::NavComponent::_NavComponentTypeUID = UFG::NavComponent::_TypeIDesc.mChildBitMask | (UFG::NavComponent::_TypeIDesc.mBaseTypeIndex << 25);
  }
  return &UFG::NavComponent::_TypeIDesc;
}

// File Line: 131
// RVA: 0x2624D0
void __fastcall UFG::NavComponent::SetPathingModule<UFG::NavModulePathing>(UFG::NavComponent *this)
{
  UFG::NavComponent *v1; // rbx
  UFG::NavModulePathing *v2; // rcx
  UFG::allocator::free_link *v3; // rax
  UFG::NavModulePathing *v4; // rax

  v1 = this;
  v2 = this->m_pNavModulePathing;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor(v2, 1u);
    v1->m_pNavModulePathing = 0i64;
  }
  v3 = UFG::qMalloc(0x240ui64, "SetPathingModule", 0i64);
  if ( v3 )
  {
    UFG::NavModulePathing::NavModulePathing((UFG::NavModulePathing *)v3, v1);
    v1->m_pNavModulePathing = v4;
  }
  else
  {
    v1->m_pNavModulePathing = 0i64;
  }
}

// File Line: 143
// RVA: 0x262440
void __fastcall UFG::NavComponent::SetLocalModule<UFG::NavModuleLocalNone>(UFG::NavComponent *this)
{
  UFG::NavComponent *v1; // rbx
  UFG::NavModuleLocal *v2; // rcx
  UFG::allocator::free_link *v3; // rax
  UFG::allocator::free_link *v4; // rdi

  v1 = this;
  v2 = this->m_pNavModuleLocal;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor(v2, 1u);
    v1->m_pNavModuleLocal = 0i64;
  }
  v3 = UFG::qMalloc(0xC0ui64, "SetLocalModule", 0i64);
  v4 = v3;
  if ( v3 )
  {
    UFG::NavModuleLocal::NavModuleLocal((UFG::NavModuleLocal *)v3, v1);
    v4->mNext = (UFG::allocator::free_link *)&UFG::NavModuleLocalNone::`vftable';
    v1->m_pNavModuleLocal = (UFG::NavModuleLocal *)v4;
  }
  else
  {
    v1->m_pNavModuleLocal = 0i64;
  }
}

// File Line: 155
// RVA: 0x262390
void __fastcall UFG::NavComponent::SetControllerModule<UFG::NavModuleController>(UFG::NavComponent *this)
{
  UFG::NavComponent *v1; // rbx
  UFG::NavModuleController *v2; // rcx
  UFG::allocator::free_link *v3; // rax
  float v4; // xmm1_4
  float v5; // xmm2_4

  v1 = this;
  v2 = this->m_pNavModuleController;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor(v2, 1u);
    v1->m_pNavModuleController = 0i64;
  }
  v3 = UFG::qMalloc(0x20ui64, "SetControllerModule", 0i64);
  if ( v3 )
  {
    v3->mNext = (UFG::allocator::free_link *)&UFG::NavModuleController::`vftable';
    v3[1].mNext = (UFG::allocator::free_link *)v1;
    v4 = UFG::qVector3::msZero.y;
    v5 = UFG::qVector3::msZero.z;
    *(float *)&v3[2].mNext = UFG::qVector3::msZero.x;
    *((float *)&v3[2].mNext + 1) = v4;
    *(float *)&v3[3].mNext = v5;
    HIDWORD(v3[3].mNext) = 0;
    v1->m_pNavModuleController = (UFG::NavModuleController *)v3;
  }
  else
  {
    v1->m_pNavModuleController = 0i64;
  }
}

