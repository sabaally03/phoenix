///*void OUT(void)
//{
//  s = 2;
//  set_bits();
//  biggestt();
//
//  if (ro || ro)
//  {
//    while (big_sensor_num < 8)
//    {
//      biggestt();
//      set_bits();
//      if (ro)
//      {
//        Move(12);
//      }
//      else if (fo || fi)
//      {
//        if (fo) Move(9);
//        else if (fi)
//        {
//          while (!fo)
//          {
//            Move(9);
//            set_bits();
//          }
//        }
//      }
//      else if (bo || bi)
//      {
//        if (bo) Move(15);
//        else if (bi)
//        {
//          while (!bo /*&& srfB < 50*/)
//          {
//            Move(15);
//            set_bits();
//          }
//        }
//      }
//      else if (ri)
//      {
//        while (!ro /*&& srfR < 50*/)
//        {
//          Move(12);
//          set_bits();
//        }
//      }
//      else
//        STOP();
//    }
//    ////////////////////////////////////////// Khareje While /////////////////////////////////////////////////
//    if (ro)
//    {
//      Move(12);
//    }
//    else if (fo || fi)
//    {
//      if (fa) Move(9);
//      else if (fi)
//      {
//        while (!fo)
//        {
//          Move(9);
//          set_bits();
//        }
//      }
//    }
//    else if (bo || bi)
//    {
//      if (ba) Move(15);
//      else if (bb)
//      {
//        while (!bo /*&& srfB < 50*/)
//        {
//          Move(15);
//          set_bits();
//        }
//      }
//    }
//    else if (ri)
//    {
//      while (!ro /*&& srfR < 50*/)
//      {
//        Move(12);
//        set_bits();
//      }
//    }
//    else STOP();
//
//  }
//  else if (lo || li)
//  {
//    //boogh();
//    while (big_sensor_num > 8)
//    {
//      biggestt();
//      set_bits();
//      if (lo)
//      {
//        Move(4);
//      }
//      else if (fo || fi)
//      {
//        if (fo) {
//          Move(7);
//        }
//        else if (fi)
//        {
//          while (!fo)
//          {
//            Move(7);
//            set_bits();
//            /* if (srfB < 50)
//              {
//               Move(8);
//               delay(300);
//               break;
//              }*/
//          }
//        }
//        if (li)
//        {
//          while (!la)
//          {
//            set_bits();
//            Move(4);
//          }
//          if (rb || ra)
//          {
//            while (!la)
//            {
//              set_bits();
//              Move(4);
//            }
//          }
//        }
//      }
//      else if (bo || bi)
//      {
//        if (bo) Move(1);
//        else if (bi)
//        {
//          while (!bo /*&& srfB < 50*/)
//          {
//            Move(1);
//            set_bits();
//          }
//        }
//      }
//      else if (li)
//      {
//        while (!lo /*&& srfL < 50*/)
//        {
//          Move(4);
//          set_bits();
//        }
//      }
//      else STOP();
//    }
//    if (lo)
//    {
//      Move(4);
//    }
//    else if (fo || fi)
//    {
//      if (fo) Move(7);
//      else if (fi)
//      {
//        while (!fo)
//        {
//          Move(7);
//          set_bits();
//          /*if (srfB < 50)
//            {
//            Move(8);
//            delay(300);
//            break;
//            }*/
//        }
//      }
//    }
//    else if (bo || bi)
//    {
//      if (bo) Move(1);
//      else if (bi)
//      {
//        while (!bo /*&& srfB < 50*/)
//        {
//          Move(1);
//          set_bits();
//        }
//      }
//    }
//    else if (li)
//    {
//      while (!lo /*&& srfL < 50*/)
//      {
//        Move(4);
//        set_bits();
//      }
//    }
//    else STOP();
//  }
//  else if (fo || fi)
//  {
//    while (big_sensor_num > 11 || big_sensor_num < 5)
//    {
//      biggestt();
//      biggestt();
//      set_bits();
//      if (fo)
//      {
//        Move(8);
//      }
//      else if (ro || ri)
//      {
//        if (ro) Move(9);
//        else if (ri)
//        {
//          while (!ro /*&& srfR < 50*/)
//          {
//            Move(9);
//            set_bits();
//          }
//        }
//      }
//      else if (lo || li)
//      {
//        if (lo) Move(7);
//        else if (li)
//        {
//          while (!lo /*&& srfL < 50*/)
//          {
//            Move(7);
//            set_bits();
//          }
//        }
//      }
//      else if (fi)
//      {
//        while (!fo)
//        {
//          Move(8);
//          set_bits();
//          /* if (srfB < 50)
//            {
//             Move(8);
//             delay(300);
//             break;
//            }*/
//        }
//      }
//      else STOP();
//    }
//    if (fo)
//    {
//      Move(8);
//    }
//    else if (ro || ri)
//    {
//      if (ro) Move(9);
//      else if (ri)
//      {
//        while (!ro/* && srfR < 50*/)
//        {
//          Move(9);
//          set_bits();
//        }
//      }
//    }
//    else if (lo || li)
//    {
//      if (lo) Move(7);
//      else if (li)
//      {
//        while (!lo /*&& srfL < 50*/)
//        {
//          Move(7);
//          set_bits();
//        }
//      }
//    }
//    else if (fi)
//    {
//      while (!fo)
//      {
//        Move(8);
//        set_bits();
//      }
//    }
//    else STOP();
//  }
//
//  else if (bo || bi)
//  {
//    while (big_sensor_num < 13 && big_sensor_num > 3)
//    {
//      biggestt();
//      biggestt();
//      set_bits();
//      if (bo)
//      {
//        Move(0);
//      }
//      else if (ro || ri)
//      {
//        if (ro) Move(15);
//        else if (ri)
//        {
//          while (!ro /*&& srfR < 50*/)
//          {
//            Move(15);
//            set_bits();
//          }
//        }
//      }
//      else if (lo || li)
//      {
//        if (lo) Move(1);
//        else if (li)
//        {
//          while (!lo /*&& srfL < 50*/)
//          {
//            Move(1);
//            set_bits();
//          }
//        }
//      }
//      else if (bi)
//      {
//        while (!bo /*&& srfB < 50*/)
//        {
//          Move(0);
//          set_bits();
//        }
//      }
//      else STOP();
//    }
//    if (bo)
//    {
//      Move(0);
//    }
//    else if (ro || ri)
//    {
//      if (ro) Move(15);
//      else if (ri)
//      {
//        while (!ro /*&& srfR < 50*/)
//        {
//          Move(15);
//          set_bits();
//        }
//      }
//    }
//    else if (lo || li)
//    {
//      if (lo) Move(1);
//      else if (li)
//      {
//        while (!lo /*&& srfL < 50*/)
//        {
//          Move(1);
//          set_bits();
//        }
//      }
//    }
//    else if (bi)
//    {
//      while (!bo /*&& srfB < 50*/)
//      {
//        Move(0);
//        set_bits();
//      }
//    }
//    else STOP();
//  }
//
//  else
//  {
//    if (big_sensor > noise) follow();
//    else STOP();
//  }
//}
