// File Line: 34
// RVA: 0x140830
void __fastcall UFG::RegionContainmentInfo::RegionContainmentInfo(UFG::RegionContainmentInfo *this)
{
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *v3; // rbx

  this->vfptr = (UFG::RegionContainmentInfoVtbl *)&UFG::RegionContainmentInfo::`vftable;
  this->m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&this->m_regionsContainedIn.size = 0i64;
  p = this->m_regionsContainedIn.p;
  if ( p )
  {
    v3 = p - 1;
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  this->m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&this->m_regionsContainedIn.size = 0i64;
}

// File Line: 36
// RVA: 0x141530
void __fastcall UFG::RegionContainmentInfo::~RegionContainmentInfo(UFG::RegionContainmentInfo *this)
{
  UFG::qSymbol *p; // rcx
  UFG::qSymbol *v3; // rbx
  UFG::qSymbol *v4; // rcx
  UFG::qSymbol *v5; // rbx

  this->vfptr = (UFG::RegionContainmentInfoVtbl *)&UFG::RegionContainmentInfo::`vftable;
  p = this->m_regionsContainedIn.p;
  if ( p )
  {
    v3 = p - 1;
    `eh vector destructor iterator(p, 4ui64, p[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v3);
  }
  this->m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&this->m_regionsContainedIn.size = 0i64;
  v4 = this->m_regionsContainedIn.p;
  if ( v4 )
  {
    v5 = v4 - 1;
    `eh vector destructor iterator(v4, 4ui64, v4[-1].mUID, (void (__fastcall *)(void *))_);
    operator delete[](v5);
  }
  this->m_regionsContainedIn.p = 0i64;
  *(_QWORD *)&this->m_regionsContainedIn.size = 0i64;
}

