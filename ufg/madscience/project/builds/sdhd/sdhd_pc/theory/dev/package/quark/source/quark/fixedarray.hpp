// File Line: 52
// RVA: 0x32A1D0
void __fastcall UFG::qFixedArray<PedFormationPairing,10>::qFixedArray<PedFormationPairing,10>(UFG::qFixedArray<PedFormationPairing,10> *this)
{
  *(_QWORD *)&this->p[0].m_MyPosition.x = 0i64;
  *(_QWORD *)&this->p[1].m_MyPosition.x = 0i64;
  this->p[0].m_MyPosition.z = 0.0;
  this->p[1].m_MyPosition.z = 0.0;
  *(_QWORD *)&this->p[2].m_MyPosition.x = 0i64;
  this->p[2].m_MyPosition.z = 0.0;
  *(_QWORD *)&this->p[3].m_MyPosition.x = 0i64;
  this->p[3].m_MyPosition.z = 0.0;
  *(_QWORD *)&this->p[4].m_MyPosition.x = 0i64;
  this->p[4].m_MyPosition.z = 0.0;
  *(_QWORD *)&this->p[5].m_MyPosition.x = 0i64;
  this->p[5].m_MyPosition.z = 0.0;
  *(_QWORD *)&this->p[6].m_MyPosition.x = 0i64;
  this->p[6].m_MyPosition.z = 0.0;
  *(_QWORD *)&this->p[7].m_MyPosition.x = 0i64;
  this->p[7].m_MyPosition.z = 0.0;
  *(_QWORD *)&this->p[8].m_MyPosition.x = 0i64;
  this->p[8].m_MyPosition.z = 0.0;
  *(_QWORD *)&this->p[9].m_MyPosition.x = 0i64;
  this->p[0].m_pMe = 0i64;
  this->p[0].m_pMyPair = 0i64;
  this->p[9].m_MyPosition.z = 0.0;
  this->p[1].m_pMe = 0i64;
  this->p[1].m_pMyPair = 0i64;
  this->p[2].m_pMe = 0i64;
  this->p[2].m_pMyPair = 0i64;
  this->p[3].m_pMe = 0i64;
  this->p[3].m_pMyPair = 0i64;
  this->p[4].m_pMe = 0i64;
  this->p[4].m_pMyPair = 0i64;
  this->p[5].m_pMe = 0i64;
  this->p[5].m_pMyPair = 0i64;
  this->p[6].m_pMe = 0i64;
  this->p[6].m_pMyPair = 0i64;
  this->p[7].m_pMe = 0i64;
  this->p[7].m_pMyPair = 0i64;
  this->p[8].m_pMe = 0i64;
  this->p[8].m_pMyPair = 0i64;
  this->p[9].m_pMe = 0i64;
  this->p[9].m_pMyPair = 0i64;
  this->size = 0;
}

// File Line: 70
// RVA: 0x332FB0
void __fastcall UFG::qFixedArray<UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent>,4>::~qFixedArray<UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent>,4>(UFG::qFixedArray<UFG::qSafePointer<UFG::GroupComponent,UFG::GroupComponent>,4> *this)
{
  this->size = 0;
  `eh vector destructor iterator'(
    this->p,
    0x18ui64,
    4,
    (void (__fastcall *)(void *))UFG::qSafePointer<AnimationGroup,AnimationGroup>::~qSafePointer<AnimationGroup,AnimationGroup>);
}

