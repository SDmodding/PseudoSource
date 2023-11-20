// File Line: 26
// RVA: 0xB8720
void __fastcall UFG::BroadPhaseHandler::maxPositionExceededCallback(UFG::BroadPhaseHandler *this, hkpEntity *entity)
{
  void (__fastcall *v2)(hkpEntity *); // rax

  v2 = this->mCallback;
  if ( v2 )
    v2(entity);
}

