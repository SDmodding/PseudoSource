// File Line: 48
// RVA: 0x64710
void __fastcall Render::SkyMarshall::SkydomeResource::SkydomeResource(Render::SkyMarshall::SkydomeResource *this)
{
  this->mNameUID.mUID = -1;
  this->modelResource[0].rotation = 0.0;
  this->modelResource[1].rotation = 0.0;
  this->modelResource[2].rotation = 0.0;
  this->modelResource[3].rotation = 0.0;
  this->modelResource[4].rotation = 0.0;
  *(_QWORD *)&this->modelResource[5].rotation = 0i64;
  UFG::qString::qString(&this->texture_pack_name);
}

// File Line: 135
// RVA: 0x64760
void __fastcall Render::SkyMarshall::WispIndexBuffer::WispIndexBuffer(Render::SkyMarshall::WispIndexBuffer *this)
{
  Render::SkyMarshall::WispIndexBuffer *v1; // rbx

  v1 = this;
  `eh vector constructor iterator'(
    this->mBufferHandle,
    0x20ui64,
    2,
    (void (__fastcall *)(void *))Illusion::BufferHandle::BufferHandle);
  v1->mNumWisps = 0;
  v1->mOutOfSync = 0;
}

