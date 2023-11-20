// File Line: 13
// RVA: 0x1C1730
void __fastcall Render::FlareInstance::FlareInstance(Render::FlareInstance *this)
{
  UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *v1; // rax

  v1 = (UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance> *)&this->mPrev;
  v1->mPrev = v1;
  v1->mNext = v1;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FlareInstance::`vftable;
  Render::Flare::Flare(&this->mFlare);
}

