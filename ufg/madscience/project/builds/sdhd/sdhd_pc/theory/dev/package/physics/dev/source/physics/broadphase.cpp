// File Line: 26
// RVA: 0xB8720
void __fastcall UFG::BroadPhaseHandler::maxPositionExceededCallback(UFG::BroadPhaseHandler *this, hkpEntity *entity)
{
  void (__fastcall *mCallback)(hkpEntity *); // rax

  mCallback = this->mCallback;
  if ( mCallback )
    mCallback(entity);
}

