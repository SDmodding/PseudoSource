// File Line: 19
// RVA: 0x81AE0
void __fastcall VideoFrameManager::FrameDataCallback(char *rgba, unsigned int width, unsigned int height)
{
  Broadcaster *Broadcaster; // rax

  Broadcaster = Broadcaster::GetBroadcaster();
  Broadcaster::SubmitFrame(Broadcaster, rgba, width, height);
}

