// File Line: 67
// RVA: 0x1456340
__int64 dynamic_initializer_for__gSavedTextureFilename__()
{
  UFG::qString::qString(&gSavedTextureFilename, &customWorldMapCaption);
  return atexit(dynamic_atexit_destructor_for__gSavedTextureFilename__);
}

// File Line: 75
// RVA: 0x1456070
__int64 dynamic_initializer_for__gEnvCaptureSectionName__()
{
  UFG::qString::qString(&gEnvCaptureSectionName);
  return atexit(dynamic_atexit_destructor_for__gEnvCaptureSectionName__);
}

