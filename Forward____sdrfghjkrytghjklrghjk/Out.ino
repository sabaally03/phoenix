void fallout()
{
  int kaj;
  int bigball;
  int smallball;
  kaf_setup();
  set_kaf();
  set_bits();
  biggest();
  read_compass();
  if (nahang = 0)
  {
    kaj = bearing ;
  }
  //  if (nahang = 1) {
  //    kaj = zard1 ;
  //  }
  /////////// Right OUT////////////
  if (ro || ri)
  {
    Move(12);
    ///////////
    if (kaj <= 15 && kaj > -90)
    {
      if (abs(kaj) <= 15)
      {
        bigball = 9;   smallball = 1;
      }
      else
      {
        bigball = 11;   smallball = 1;
      }
      while (big_sensor_num >= smallball && big_sensor_num <= bigball )
      {
        set_bits();
        read_compass();
        if (abs(kaj) <= 15)
        {
          bigball = 9;   smallball = 1;
        }
        else
        {
          bigball = 11;  smallball = 1;
        }

        if (fo || fi)
        {
          Move(10);
          if (fi)
          {
            while (!fo)
            {
              read_compass();
              set_bits();
              MOVE(10);
            }
          }
        }
        else if (bo || bi)
        {
          Move(15);
          if (bi)
          {
            while (!bo)
            {
              read_compass();
              set_bits();
              MOVE(15);
            }
          }
        }
        else if (ri)
        {
          while (!ro)
          {
            read_compass();
            set_bits();
            Move(12);
          }
        }
        else if (ro)
          Move(12);
        else
          STOP();
      }
    }
    ////////oonvar kaj/////////
    else if (kaj > 15 && kaj <= 90)
    {
      smallball = 7;      bigball = 14;
      while ((big_sensor_num < smallball || big_sensor_num > bigball)     )
      {
        set_bits();
        read_compass();
        //        if (abs(kaj) <= 15)
        //        {
        //          bigball = 0;    smallball = 8;
        //        }
        if (fo || fi)
        {
          Move(9);
          if (fi)
          {
            while (!fo)
            {
              read_compass();
              set_bits();
              MOVE(9);
            }
          }
        }
        else if (bo || bi)
        {
          Move(14);
          if (bi)
          {
            while (!bo)
            {
              read_compass();
              set_bits();
              MOVE(14);
            }
          }
        }
        else if (ri)
        {
          while (!ro)
          { read_compass();
            set_bits();
            Move(12);
          }
        }
        else if (ro)
          Move(12);
        else
          STOP();
      }
    }
  }
  ///////////end of right out
  else if ( li || lo )
  {
    Move(4);
    if (kaj >= -15 && kaj < 90)
    {
      if (abs (kaj) <= 15)
      {
        bigball = 15; smallball = 7;
      }
      else if (kaj > 15 && kaj < 90)
      {
        bigball = 13; smallball = 2;
      }
      while (big_sensor_num > smallball && big_sensor_num < bigball     )
      {
        set_bits();
        read_compass();
        if (abs (kaj) <= 15)
        {
          bigball = 15; smallball = 7;
        }
        else if (kaj > 15 && kaj < 90)
        {
          bigball = 13; smallball = 2;
        }
        if (fo || fi)
        {
          Move(5);
          if (fi)
          {
            while (!fo)
            {
              set_bits();
              read_compass();
              MOVE(5);
            }
          }
        }
        else if (bo || bi)
        {
          Move(2);
          if (bi)
          {
            while (!bo)
            {
              set_bits();
              read_compass();
              MOVE(2);
            }
          }
        }
        else if (li)
        {
          while (!lo)
          { read_compass();
            set_bits();
            Move(4);
          }
          Move(4);
        }
        else if (lo)
          Move(4);
        else
          STOP();
      }
    }
    else if (kaj < -15 && kaj > -90)
    {
      smallball = 2;    bigball = 10;
      while ((big_sensor_num < smallball || big_sensor_num > bigball)     )
      {
        set_bits();
        read_compass();
        //        if (abs(kaj) <= 15)
        //        {
        //          bigball = 180;    smallball = 0;
        //        }
        if (fo || fi)
        {
          Move(7);
          if (fi)
          {
            while (!fo)
            { read_compass();
              set_bits();
              MOVE(7);
            }
          }
        }
        else if (bo || bi)
        {
          Move(3);
          if (bi)
          {
            while (!bo)
            {
              read_compass();
              set_bits();
              MOVE(3);
            }
          }
        }
        else if (li)
        {
          while (!lo)
          {
            read_compass();
            set_bits();
            Move(4);
          }
          Move(4);
        }
        else if (lo)
          Move(4);
        else
          STOP();
      }
    }
    //if (ba < smallball || ba > bigball) follow();
  }
  /////////end of left out
  else if (fo || fi)
  {
    Move(8);
    if (abs(kaj) <= 15)
    {
      bigball = 10;   smallball = 2;
    }
    else if (kaj > 15 && kaj < 90)
    {
      bigball = 15; smallball = 5;
    }
    else if (kaj < -15 && kaj > -90)
    {
      bigball = 15; smallball = 2;
    }
    while ((big_sensor_num < smallball) || (big_sensor_num > bigball) )
    {
      set_bits();
      read_compass();
      if (lo || li)
      {
        Move(5);
        if (li)
        {
          while (!lo)
          {
            read_compass();
            set_bits();
            MOVE(6);
          }
        }
      }
      else if (ro || ri)
      {
        Move(10);
        if (ri)
        {
          while (!ro)
          {
            read_compass();
            set_bits();
            MOVE(10);
          }
        }
      }
      else if (fi)
      {
        while (!fo)
        {
          read_compass();
          set_bits();
          Move(8);
        }
        Move(8);
      }
      else if (fo)
        Move(8);
      else
        STOP();
    }
  }
  else if (bo || bi)
  {
    Move(0);
    if (abs (kaj) <= 15)
    {
      bigball = 13;  smallball = 7;
    }
    else if (kaj < -15 && kaj > -90)
    {
      bigball = 11;  smallball = 4;
    }
    else if (kaj > 15 && kaj < 90)
    {
      bigball = 11;  smallball = 4;
    }
    while ((big_sensor_num > smallball) && (big_sensor_num < bigball)     )
    {
      set_bits();
      read_compass();
      if (lo || li)
      {
        Move(2);
        if (li )
        {
          while (!lo)
          { read_compass();
            set_bits();
            MOVE(2);
          }
        }
      }
      else if (ro || ri)
      {
        Move(15);
        if (ri)
        {
          while (!ro)
          {
            read_compass();
            set_bits();
            MOVE(15);
          }
        }
      }
      else if (bi)
      {
        while (!bo)
        {
          read_compass();
          set_bits();
          Move(0);
        }
      }
      else if (bo)
        Move(0);
      else
        STOP();
    }
  }
  else {
    follow();
  }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void nemyam ()
{
  set_bits();
  read_compass();
  ///////////////////////////////////////out_r//////////////////////////////////////////
  if (ro == 1 || ri == 1)
  {
    if (ri)
    {
      while (!ro)
      {
        read_compass();
        set_bits();
        Move(12);
      }
    }
    else if (ro)
    {
      Move(12);
    }

    else if (fo || fi )
    {
      if (fi)
      {
        while (!fo)
        {
          set_bits();
          read_compass();
          MOVE(10);
        }
      }
      else if (fo)
        Move(10);
      else STOP();
    }
    else if (bo || bi )
    {
      if (bi)
      {
        while (!bo)
        {
          set_bits();
          read_compass();
          MOVE(14);
        }
      }
      else if (bo)
        Move(14);
      else STOP();
    }
    else STOP();
  }
  ///////////////////////////////////////out_L//////////////////////////////////////////
  if (lo == 1 || li == 1)
  {
    if (li)
    {
      while (!lo)
      {
        read_compass();
        set_bits();
        Move(4);
      }
    }
    else if (!lo)
    {
      Move(4);
    }

    else if (fo || fi )
    {
      if (fi)
      {
        while (!fo)
        {
          set_bits();
          read_compass();
          MOVE(6);
        }
      }
      else if (fo)
        Move(6);
      else STOP();
    }
    else if (bo || bi )
    {
      if (bi)
      {
        while (!bo)
        {
          set_bits();
          read_compass();
          MOVE(2);
        }
      }
      else if (bo)
        Move(2);
      else STOP();
    }
    else STOP();
  }
  ///////////////////////////////////////out_F//////////////////////////////////////////
  if (fo == 1 || fi == 1)
  {
    if (fi)
    {
      while (!fo)
      {
        read_compass();
        set_bits();
        Move(8);
      }
    }
    else if (fo)
    {
      Move(8);
    }

    else if (ro || ri )
    {
      if (ri)
      {
        while (!ro)
        {
          set_bits();
          read_compass();
          MOVE(10);
        }
      }
      else if (ri)
        Move(10);
      else STOP();
    }
    else if (lo || li )
    {
      if (li)
      {
        while (!lo)
        {
          set_bits();
          read_compass();
          MOVE(6);
        }
      }
      else if (lo)
        Move(6);
      else STOP();
    }
    else STOP();
  }
  ///////////////////////////////////////out_B//////////////////////////////////////////
  if (bo == 1 || bi == 1)
  {
    if (bi)
    {
      while (!bo)
      {
        read_compass();
        set_bits();
        Move(0);
      }
    }
    else if (bo)
    {
      Move(0);
    }
    else if (ro || ri )
    {
      if (ri)
      {
        while (!ro)
        {
          set_bits();
          read_compass();
          Move(14);
        }
      }
      else if (ro)
        Move(14);
      else STOP();
    }
    else if (lo || li )
    {
      if (li)
      {
        while (!lo)
        {
          set_bits();
          read_compass();
          MOVE(2);
        }
      }
      else if (lo)
        Move(2);
      else STOP();
    }
    else STOP();
  }
  else STOP();
}
