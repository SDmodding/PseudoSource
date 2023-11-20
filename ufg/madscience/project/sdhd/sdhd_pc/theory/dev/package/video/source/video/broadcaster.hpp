// File Line: 64
// RVA: 0x81BC0
Broadcaster *__fastcall Broadcaster::GetBroadcaster()
{
  if ( !(`Broadcaster::GetBroadcaster::`2::`local static guard & 1) )
  {
    `Broadcaster::GetBroadcaster::`2::`local static guard |= 1u;
    UFG::qString::qString(&`Broadcaster::GetBroadcaster::`2::singleton.mUserName);
    UFG::qString::qString(&stru_142165FA8);
    qword_1421666E0 = 0i64;
    unk_1421666D8 = 0i64;
    mem = 0i64;
    unk_1421666E8 = 0i64;
    unk_1421666D0 = 0;
    unk_1421666D4 = 0;
    unk_1421666D6 = 0;
    atexit(`Broadcaster::GetBroadcaster::`2::`dynamic atexit destructor for singleton);
  }
  return &`Broadcaster::GetBroadcaster::`2::singleton;
}

