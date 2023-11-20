// File Line: 143
// RVA: 0xE35E0
void __fastcall UFG::NavComponent::SetLocalModule<UFG::NavModuleLocalRVO>(UFG::NavComponent *this)
{
  UFG::NavComponent *v1; // rbx
  UFG::NavModuleLocal *v2; // rcx
  char *v3; // rax
  UFG::NavModuleLocal *v4; // rax

  v1 = this;
  v2 = this->m_pNavModuleLocal;
  if ( v2 )
  {
    v2->vfptr->__vecDelDtor(v2, 1u);
    v1->m_pNavModuleLocal = 0i64;
  }
  v3 = UFG::qMalloc(0x180ui64, "SetLocalModule", 0i64);
  if ( v3 )
  {
    UFG::NavModuleLocalRVO::NavModuleLocalRVO((UFG::NavModuleLocalRVO *)v3, v1);
    v1->m_pNavModuleLocal = v4;
  }
  else
  {
    v1->m_pNavModuleLocal = 0i64;
  }
}

// File Line: 155
// RVA: 0x3290F0
void __fastcall UFG::NavComponent::SetControllerModule<UFG::NavModuleControllerPedestrian>(UFG::NavComponent *this)
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
  v3 = UFG::qMalloc(0x28ui64, "SetControllerModule", 0i64);
  if ( v3 )
  {
    v3->mNext = (UFG::allocator::free_link *)&UFG::NavModuleController::`vftable;
    v3[1].mNext = (UFG::allocator::free_link *)v1;
    v4 = UFG::qVector3::msZero.y;
    v5 = UFG::qVector3::msZero.z;
    *(float *)&v3[2].mNext = UFG::qVector3::msZero.x;
    *((float *)&v3[2].mNext + 1) = v4;
    *(float *)&v3[3].mNext = v5;
    HIDWORD(v3[3].mNext) = 0;
    v3->mNext = (UFG::allocator::free_link *)&UFG::NavModuleControllerPedestrian::`vftable;
    LOBYTE(v3[4].mNext) = 0;
    HIDWORD(v3[4].mNext) = -1082130432;
    v1->m_pNavModuleController = (UFG::NavModuleController *)v3;
  }
  else
  {
    v1->m_pNavModuleController = 0i64;
  }
}

