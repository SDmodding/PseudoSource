// File Line: 13
// RVA: 0x1C1730
void __fastcall Render::FlareInstance::FlareInstance(Render::FlareInstance *this)
{
  this->mPrev = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->mNext = &this->UFG::qNode<Render::FXComponentInstance,Render::FXComponentInstance>;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FXComponentInstance::`vftable;
  *(_QWORD *)&this->mForceSuspendState = 0i64;
  *(_WORD *)&this->mIsActive = 0;
  this->vfptr = (Render::FXComponentInstanceVtbl *)&Render::FlareInstance::`vftable;
  Render::Flare::Flare(&this->mFlare);
}

