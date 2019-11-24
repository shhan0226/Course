public class animation extends Applet {
   PlayAnimationLeft aniImageLeft = null;
   PlayAnimationRight aniImageRight = null;
   Applet applet;
   public void init() {
      applet = this;
      Button button1 = new Button("LEFT ");
      button1.addActionListener(new Button1Listener());
      add(button1);
      Button button2 = new Button("RIGHT");
      button2.addActionListener(new Button2Listener());
      add(button2);
      Button button3 = new Button("BOTH ");
      button3.addActionListener(new Button3Listener());
      add(button3);
   }
   public void start() {
      if (aniImageLeft == null) {
         aniImageLeft = new PlayAnimationLeft(this);
         aniImageLeft.start();
      }
      if (aniImageRight == null) {
         aniImageRight = new PlayAnimationRight(this);
         aniImageRight.start();
      }
   }
   public void stop() {
      if ((aniImageLeft != null) && (aniImageLeft.isAlive())) {
         aniImageLeft.stop();
         aniImageLeft = null;
      }
      if ((aniImageRight != null) && (aniImageRight.isAlive())) {
         aniImageRight.stop();
         aniImageRight = null;
      }
   }
   class Button1Listener implements ActionListener {
      public void actionPerformed(ActionEvent e) {
         if ((aniImageRight != null) && (aniImageRight.isAlive())) {
            aniImageRight.stop();
            aniImageRight = null;
         }
         if (aniImageLeft == null) {
            aniImageLeft = new PlayAnimationLeft(applet);
            aniImageLeft.start();
         }
      }
   }

   class Button2Listener implements ActionListener {
      public void actionPerformed(ActionEvent e) {
         if ((aniImageLeft != null) && (aniImageLeft.isAlive())) {
            aniImageLeft.stop();
            aniImageLeft = null;
         }
         if (aniImageRight == null) {
            aniImageRight = new PlayAnimationRight(applet);
            aniImageRight.start();
         }
      }
   }

   class Button3Listener implements ActionListener {
      public void actionPerformed(ActionEvent e) {
         if (aniImageLeft == null) {
            aniImageLeft = new PlayAnimationLeft(applet);
            aniImageLeft.start();
         }
         if (aniImageRight == null) {
            aniImageRight = new PlayAnimationRight(applet);
            aniImageRight.start();
         }
      }
   }
}

class PlayAnimationRight extends Thread {
   Applet applet;
   Image[] images;
   int curImage = -1;
   public PlayAnimationRight(Applet a) {
      applet = a;
      images = new Image[8];
      for (int i=0; i<8; i++)
         images[i] = applet.getImage(a.getDocumentBase(),"penguin"+i);
   }
   public void run() {
      while(true) {
         if (++curImage >= images.length)
            curImage = 0;
         applet.getGraphics().drawImage(images[curImage], 180, 50, applet);
         try {
            Thread.sleep(200);
         } catch (InterruptedException e) {}
      }
   }
}

class PlayAnimationLeft extends Thread {
   Applet applet;
   Image[] images;
   int curImage = -1;
   public PlayAnimationLeft(Applet a) {
      applet = a;
      images = new Image[8];
      for (int i=0; i<8; i++)
         images[i] = applet.getImage(a.getDocumentBase(),"penguin"+i);
   }
   public void run() {
      while(true) {
         if (++curImage >= images.length)
            curImage = 0;
         applet.getGraphics().drawImage(images[curImage], 40, 50, applet);
         try {
            Thread.sleep(200);
         } catch (InterruptedException e) {}
      }
   }
}
