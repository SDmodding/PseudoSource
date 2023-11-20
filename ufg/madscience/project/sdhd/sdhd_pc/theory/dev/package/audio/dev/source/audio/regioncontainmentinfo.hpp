// File Line: 34
// RVA: 0x140830
void __fastcall UFG::RegionContainmentInfo::RegionContainmentInfo(UFG::RegionContainmentInfo *this)
{
  UFG::RegionContainmentInfo *v1; // rdi
  UFG::qSymbol *v2; // rcx
  UFG::qSymbol *v3; // rbx

  v1 = this;
  this->vfptr = (UFG::RegionContainmentInfoVtbl *)&UFG::RegionContainmentInfo::`vftable';
  this->m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&this->m_regionsContainedIn.size = 0i64;
  v2 = this->m_regionsContainedIn.p;
  if ( v2 )
  {
    v3 = v2 - 1;
    `eh vector destructor iterator'(v2, 4ui64, v2[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  v1->m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&v1->m_regionsContainedIn.size = 0i64;
}

// File Line: 36
// RVA: 0x141530
void __fastcall UFG::RegionContainmentInfo::~RegionContainmentInfo(UFG::RegionContainmentInfo *this)
{
  UFG::RegionContainmentInfo *v1; // rdi
  UFG::qSymbol *v2; // rcx
  UFG::qSymbol *v3; // rbx
  UFG::qSymbol *v4; // rcx
  UFG::qSymbol *v5; // rbx

  v1 = this;
  this->vfptr = (UFG::RegionContainmentInfoVtbl *)&UFG::RegionContainmentInfo::`vftable';
  v2 = this->m_regionsContainedIn.p;
  if ( v2 )
  {
    v3 = v2 - 1;
    `eh vector destructor iterator'(v2, 4ui64, v2[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  v1->m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&v1->m_regionsContainedIn.size = 0i64;
  v4 = v1->m_regionsContainedIn.p;
  if ( v4 )
  {
    v5 = v4 - 1;
    `eh vector destructor iterator'(v4, 4ui64, v4[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v5);
  }
  v1->m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&v1->m_regionsContainedIn.size = 0i64;
}

