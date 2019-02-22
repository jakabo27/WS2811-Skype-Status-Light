using System;
using System.Drawing;
using System.Windows.Forms;

namespace LyncPresenceBridge
{
    public partial class AboutForm : Form
    {
        public AboutForm()
        {
            InitializeComponent();
        }

        private void buttonAboutOK_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("https://www.hackster.io/matheus-fenner/skype-status-light-c2df6c");
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("https://github.com/f3nner/Skype-Status-Light-Bridge");
        }

        private void AboutForm_Load(object sender, EventArgs e)
        {
            //Open the window in the bottom right of the primary screen, which should be right above the Lync icon
            this.Location = new Point(Screen.PrimaryScreen.WorkingArea.Width - this.Width, Screen.PrimaryScreen.WorkingArea.Height - this.Height);
        }

        private void linkLabel3_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("https://jacobathompson.com/projects");
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            System.Diagnostics.Process.Start("https://www.instructables.com/member/jakabo27/");
        }

        private void linkLabel4_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            System.Diagnostics.Process.Start("https://www.instructables.com/id/Skype-for-Business-Status-WS2812-RGB-LED-Desk-Unde/");
        }
    }
}
