// File Line: 112
// RVA: 0xA3D840
__int64 __fastcall UFG::DxController::RawPadDataSize(UFG::DxController *this)
{
  return 44i64;
}

// File Line: 160
// RVA: 0xA3CC50
bool __fastcall UFG::Gamepad::IsConnected(UFG::Gamepad *this)
{
  return this->mIsStatusOK && !this->mUnplugged;
}

