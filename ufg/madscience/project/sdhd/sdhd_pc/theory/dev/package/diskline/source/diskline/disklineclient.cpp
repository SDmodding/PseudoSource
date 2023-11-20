// File Line: 33
// RVA: 0x146F520
__int64 UFG::_dynamic_initializer_for__smbDiskline_Mutex__()
{
  UFG::qMutex::qMutex(&UFG::smbDiskline_Mutex, &customWorldMapCaption);
  return atexit(UFG::_dynamic_atexit_destructor_for__smbDiskline_Mutex__);
}

// File Line: 138
// RVA: 0x146F4F0
__int64 UFG::_dynamic_initializer_for__mFileTimeCache__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&UFG::mFileTimeCache.mNodes.mTree);
  return atexit(UFG::_dynamic_atexit_destructor_for__mFileTimeCache__);
}

