// File Line: 34
// RVA: 0x1457D30
__int64 Illusion::_dynamic_initializer_for__gDefaultMemoryStreamer__()
{
  return atexit(Illusion::_dynamic_atexit_destructor_for__gDefaultMemoryStreamer__);
}

// File Line: 143
// RVA: 0x927F0
void __fastcall Illusion::Engine::Init(Illusion::Engine *this)
{
  Illusion::Engine *v1; // rbx

  v1 = this;
  *(_QWORD *)&this->mFrameCount = 3i64;
  this->MemoryStreamer = &Illusion::gDefaultMemoryStreamer;
  this->FrameMemory = 0i64;
  this->PrevFrameMemory = 0i64;
  this->FrameWriteMemory = 0i64;
  this->PrimitiveFrameWriteMemory = 0i64;
  this->FramePatchMemory = 0i64;
  this->FrameIndexMemory = 0i64;
  Illusion::StateSystem::Init(&Illusion::gStateSystem);
  Illusion::RenderQueueSystem::Init();
  _((AMD_HD3D *)v1);
}

// File Line: 177
// RVA: 0x95B60
void __fastcall Illusion::Engine::WaitUntilSafeToDelete(Illusion::Engine *this)
{
  Illusion::IEnginePlat::WaitUntilGPUDone((Illusion::IEnginePlat *)this);
}

// File Line: 184
// RVA: 0x8E710
void __fastcall Illusion::Engine::BeginFrame(Illusion::Engine *this)
{
  ++this->mFrameCount;
  ++this->mSafeToDeleteFrameCount;
  if ( this->mFrameCount == -1 )
    *(_QWORD *)&this->mFrameCount = -1 - this->mSafeToDeleteFrameCount;
  _((AMD_HD3D *)this);
}

// File Line: 203
// RVA: 0x91F90
void __fastcall Illusion::Engine::EndFrame(Illusion::Engine *this)
{
  _((AMD_HD3D *)this);
  Illusion::Factory::ClearFinalDeleteQueueAll();
}

// File Line: 212
// RVA: 0x95600
void __fastcall Illusion::Engine::RenderThreadProcessDeleteQueue(Illusion::Engine *this)
{
  Illusion::Factory::ProcessWaitDeleteQueueAll();
}

