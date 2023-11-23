// File Line: 143
// RVA: 0xE35E0
void __fastcall UFG::NavComponent::SetLocalModule<UFG::NavModuleLocalRVO>(UFG::NavComponent *this)
{
  UFG::NavModuleLocal *m_pNavModuleLocal; // rcx
  char *v3; // rax
  UFG::NavModuleLocal *v4; // rax

  m_pNavModuleLocal = this->m_pNavModuleLocal;
  if ( m_pNavModuleLocal )
  {
    m_pNavModuleLocal->vfptr->__vecDelDtor(m_pNavModuleLocal, 1u);
    this->m_pNavModuleLocal = 0i64;
  }
  v3 = UFG::qMalloc(0x180ui64, "SetLocalModule", 0i64);
  if ( v3 )
  {
    UFG::NavModuleLocalRVO::NavModuleLocalRVO((UFG::NavModuleLocalRVO *)v3, this);
    this->m_pNavModuleLocal = v4;
  }
  else
  {
    this->m_pNavModuleLocal = 0i64;
  }
}

// File Line: 155
// RVA: 0x3290F0
void __fastcall UFG::NavComponent::SetControllerModule<UFG::NavModuleControllerPedestrian>(UFG::NavComponent *this)
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
  v3 = UFG::qMalloc(0x28ui64, "SetControllerModule", 0i64);
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
    v3->mNext = (UFG::allocator::free_link *)&UFG::NavModuleControllerPedestrian::`vftable;
    LOBYTE(v3[4].mNext) = 0;
    HIDWORD(v3[4].mNext) = -1082130432;
    this->m_pNavModuleController = (UFG::NavModuleController *)v3;
  }
  else
  {
    this->m_pNavModuleController = 0i64;
  }
}

