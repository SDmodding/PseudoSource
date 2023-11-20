// File Line: 76
// RVA: 0x94B090
void __fastcall Scaleform::Render::ImageFileHandler::~ImageFileHandler(Scaleform::Render::ImageFileHandler *this)
{
  this->vfptr = (Scaleform::Render::ImageFileHandlerVtbl *)&Scaleform::Render::ImageFileHandler::`vftable;
}

// File Line: 204
// RVA: 0x8A4EB0
void __fastcall Scaleform::Render::ImageFileHandlerRegistry::~ImageFileHandlerRegistry(Scaleform::Render::ImageFileHandlerRegistry *this)
{
  this->vfptr = (Scaleform::Render::ImageFileHandlerRegistryVtbl *)&Scaleform::Render::ImageFileHandlerRegistry::`vftable;
  if ( this->Handlers.Data.Data )
    ((void (*)(void))Scaleform::Memory::pGlobalHeap->vfptr->Free)();
}

