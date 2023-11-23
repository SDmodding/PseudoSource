// File Line: 88
// RVA: 0x94C9C0
void __fastcall Scaleform::Render::ScopedRenderEvent::~ScopedRenderEvent(Scaleform::Render::ScopedRenderEvent *this)
{
  this->EventObj->vfptr->End(this->EventObj);
}

