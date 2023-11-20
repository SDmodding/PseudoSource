// File Line: 31
// RVA: 0x1493FF0
__int64 dynamic_initializer_for__gMemberMapClassSchema__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&gMemberMapClassSchema.mClasses.mTree);
  gMemberMapClassSchema.mSerializationStack.p = 0i64;
  *(_QWORD *)&gMemberMapClassSchema.mSerializationStack.size = 0i64;
  return atexit(dynamic_atexit_destructor_for__gMemberMapClassSchema__);
}

// File Line: 35
// RVA: 0x1494030
__int64 dynamic_initializer_for__gSerializedSymbols__()
{
  UFG::qBaseTreeRB::qBaseTreeRB(&gSerializedSymbols.mTree);
  return atexit(dynamic_atexit_destructor_for__gSerializedSymbols__);
}

