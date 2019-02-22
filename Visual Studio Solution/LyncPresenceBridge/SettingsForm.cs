using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Uctrl.Arduino;

namespace LyncPresenceBridge
{

    public partial class SettingsForm : Form
    {
        private Arduino arduino = new Arduino();
        public SettingsForm()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Properties.Settings.Default.ArduinoSerialPort = (int)numericUpDown1.Value;

            Properties.Settings.Default.Save();
            this.Close();
        }

        private void SettingsForm_Load(object sender, EventArgs e)
        {
            numericUpDown1.Value = Properties.Settings.Default.ArduinoSerialPort;
            brightSlider.Value = Properties.Settings.Default.Brightness;
            speedSlider.Value = Properties.Settings.Default.Speed;

            //Open the window in the bottom right of the primary screen, which should be right above the Lync icon
            this.Location = new Point(Screen.PrimaryScreen.WorkingArea.Width - this.Width, Screen.PrimaryScreen.WorkingArea.Height - this.Height);

            //Setup port
            arduino.OpenPort("COM" + Properties.Settings.Default.ArduinoSerialPort.ToString());

        }

        private void brightSlider_ValueChanged(object sender, EventArgs e)
        {
            //Change the brightness in settings
            Properties.Settings.Default.Brightness = (int)brightSlider.Value;

            //Send it to the Arduino
            arduino.Send("Brightness," + (int)brightSlider.Value);
        }

        private void SettingsForm_FormClosed(object sender, FormClosedEventArgs e)
        {
            if (arduino.Port.IsOpen)
            {
                arduino.Dispose();
            }
        }

        private void trackBar1_ValueChanged(object sender, EventArgs e)
        {
            //Change in settings
            Properties.Settings.Default.Speed = (int)speedSlider.Value;

            //Send it to the Arduino
            arduino.Send("Speed," + (int)speedSlider.Value);
        }
    }
}
