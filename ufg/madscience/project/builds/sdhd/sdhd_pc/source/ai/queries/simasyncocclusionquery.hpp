// File Line: 23
// RVA: 0x331DB0
void __fastcall UFG::SimAsyncOcclusionQuery::SimAsyncOcclusionQuery(UFG::SimAsyncOcclusionQuery *this)
{
  FX::HardwareOcclusionQuery::HardwareOcclusionQuery(&this->mHardwareOcclusionQuery);
}

// File Line: 24
// RVA: 0x33AF40
void __fastcall UFG::SimAsyncOcclusionQuery::~SimAsyncOcclusionQuery(UFG::SimAsyncOcclusionQuery *this)
{
  FX::HardwareOcclusionQuery::Release(&this->mHardwareOcclusionQuery);
}

