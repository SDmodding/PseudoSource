// File Line: 75
// RVA: 0xA264A0
void __fastcall UFG::UIThreadCommandQueue::GetRenderInterfaces(UFG::UIThreadCommandQueue *this, Scaleform::Render::Interfaces *p)
{
  Scaleform::Render::Interfaces *v2; // rbx
  __int64 v3; // rax

  v2 = p;
  p->pHAL = this->pHAL;
  p->pRenderer2D = this->pR2D;
  v3 = ((__int64 (*)(void))this->pHAL->vfptr[61].__vecDelDtor)();
  v2->RenderThreadID = 0i64;
  v2->pTextureManager = (Scaleform::Render::TextureManager *)v3;
}

// File Line: 219
// RVA: 0xA33B90
Scaleform::Ptr<Scaleform::Render::Renderer2D> *__fastcall UFG::UIScreenManagerBase::getRenderer2D(UFG::UIScreenManagerBase *this, Scaleform::Ptr<Scaleform::Render::Renderer2D> *result)
{
  Scaleform::Ptr<Scaleform::Render::Renderer2D> *v2; // rbx
  UFG::UIScreenManagerBase *v3; // rdi
  Scaleform::Render::Renderer2D *v4; // rcx

  v2 = result;
  v3 = this;
  v4 = this->mRenderer2D.pObject;
  if ( v4 )
    Scaleform::Render::RenderBuffer::AddRef((Scaleform::GFx::Resource *)v4);
  v2->pObject = (Scaleform::Render::Renderer2D *)v3->mRenderer2D;
  return v2;
}

