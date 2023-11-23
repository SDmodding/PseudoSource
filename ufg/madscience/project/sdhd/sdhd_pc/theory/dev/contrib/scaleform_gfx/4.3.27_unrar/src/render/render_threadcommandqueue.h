// File Line: 82
// RVA: 0xA23A60
void __fastcall Scaleform::Render::ThreadCommandQueue::~ThreadCommandQueue(Scaleform::Render::ThreadCommandQueue *this)
{
  this->vfptr = (Scaleform::Render::ThreadCommandQueueVtbl *)&Scaleform::Render::ThreadCommandQueue::`vftable;
}

// File Line: 92
// RVA: 0xA26480
void __fastcall Scaleform::Render::ThreadCommandQueue::GetRenderInterfaces(
        Scaleform::Render::ThreadCommandQueue *this,
        Scaleform::Render::Interfaces *p)
{
  p->pTextureManager = 0i64;
  p->pHAL = 0i64;
  p->pRenderer2D = 0i64;
  p->RenderThreadID = 0i64;
}

