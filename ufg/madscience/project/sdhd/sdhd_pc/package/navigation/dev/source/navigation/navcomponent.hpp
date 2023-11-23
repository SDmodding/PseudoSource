// File Line: 43
// RVA: 0x2633C0
UFG::ComponentIDDesc *__fastcall UFG::NavComponent::AccessComponentDesc()
{
  UFG::ComponentIDDesc result; // [rsp+20h] [rbp-18h] BYREF

  if ( !UFG::NavComponent::_DescInit )
  {
    UFG::NavComponent::_TypeIDesc = *UFG::Simulation_GetNewBaseDesc(&result);
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
  UFG::NavModulePathing *m_pNavModulePathing; // rcx
  UFG::allocator::free_link *v3; // rax
  UFG::NavModulePathing *v4; // rax

  m_pNavModulePathing = this->m_pNavModulePathing;
  if ( m_pNavModulePathing )
  {
    m_pNavModulePathing->vfptr->__vecDelDtor(m_pNavModulePathing, 1u);
    this->m_pNavModulePathing = 0i64;
  }
  v3 = UFG::qMalloc(0x240ui64, "SetPathingModule", 0i64);
  if ( v3 )
  {
    UFG::NavModulePathing::NavModulePathing((UFG::NavModulePathing *)v3, this);
    this->m_pNavModulePathing = v4;
  }
  else
  {
    this->m_pNavModulePathing = 0i64;
  }
}

// File Line: 143
// RVA: 0x262440
void __fastcall UFG::NavComponent::SetLocalModule<UFG::NavModuleLocalNone>(UFG::NavComponent *this)
{
  UFG::NavModuleLocal *m_pNavModuleLocal; // rcx
  UFG::allocator::free_link *v3; // rax
  UFG::NavModuleLocal *v4; // rdi

  m_pNavModuleLocal = this->m_pNavModuleLocal;
  if ( m_pNavModuleLocal )
  {
    m_pNavModuleLocal->vfptr->__vecDelDtor(m_pNavModuleLocal, 1u);
    this->m_pNavModuleLocal = 0i64;
  }
  v3 = UFG::qMalloc(0xC0ui64, "SetLocalModule", 0i64);
  v4 = (UFG::NavModuleLocal *)v3;
  if ( v3 )
  {
    UFG::NavModuleLocal::NavModuleLocal((UFG::NavModuleLocal *)v3, this);
    v4->vfptr = (UFG::NavModuleLocalVtbl *)&UFG::NavModuleLocalNone::`vftable;
    this->m_pNavModuleLocal = v4;
  }
  else
  {
    this->m_pNavModuleLocal = 0i64;
  }
}

// File Line: 155
// RVA: 0x262390
void __fastcall UFG::NavComponent::SetControllerModule<UFG::NavModuleController>(UFG::NavComponent *this)
{
  UFG::NavModuleController *m_pNavModuleController; // rcx
  UFG::allocator::free_link *v3; // rax
  float y; // xmm1_4
  float z; // xmm2_4

  m_pNavModuleController = this->m_pNavModuleController;
  if ( m_pNavModuleController )
  {
    m_pNavModuleController->vfptr->__vecDelDtor(m_pNavModuleController, 1u);
    this->m_pNavModuleController = 0i64;
  }
  v3 = UFG::qMalloc(0x20ui64, "SetControllerModule", 0i64);
  if ( v3 )
  {
    v3->mNext = (UFG::allocator::free_link *)&UFG::NavModuleController::`vftable;
    v3[1].mNext = (UFG::allocator::free_link *)this;
    y = UFG::qVector3::msZero.y;
    z = UFG::qVector3::msZero.z;
    *(float *)&v3[2].mNext = UFG::qVector3::msZero.x;
    *((float *)&v3[2].mNext + 1) = y;
    *(float *)&v3[3].mNext = z;
    HIDWORD(v3[3].mNext) = 0;
    this->m_pNavModuleController = (UFG::NavModuleController *)v3;
  }
  else
  {
    this->m_pNavModuleController = 0i64;
  }
}

