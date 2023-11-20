// File Line: 19
// RVA: 0xAAD870
void __fastcall CAkChildCtx::CAkChildCtx(CAkChildCtx *this, CAkMusicCtx *in_pParentCtx)
{
  this->m_pParentCtx = in_pParentCtx;
  this->vfptr = (CAkChildCtxVtbl *)&CAkChildCtx::`vftable';
}

// File Line: 24
// RVA: 0xAAD890
void __fastcall CAkChildCtx::~CAkChildCtx(CAkChildCtx *this)
{
  this->vfptr = (CAkChildCtxVtbl *)&CAkChildCtx::`vftable';
}

// File Line: 28
// RVA: 0xAAD8D0
void __fastcall CAkChildCtx::Connect(CAkChildCtx *this)
{
  CAkMusicCtx::AddChild(this->m_pParentCtx, this);
}

