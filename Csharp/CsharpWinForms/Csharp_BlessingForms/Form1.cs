using System;
using System.Drawing;
using System.Windows.Forms;

namespace Csharp_BlessingForms;

public partial class BlessingForms : Form
{
    private const int ShowDuration = 2000;
    private const int FadeDuration = 300;
    private System.Windows.Forms.Timer fadeTimer;
    private System.Windows.Forms.Timer closeTimer;
    private float opacityStep;
    public BlessingForms(string text)
    {
        InitializeComponent();
        this.Text = "温馨祝福";
        this.Label_Blessing.Text = text;
        this.FormBorderStyle = FormBorderStyle.None;
        this.TopMost = true;
        this.BackColor = Color.FromArgb(255, 245, 250);
        this.Opacity = 0.0f;
        fadeTimer = new System.Windows.Forms.Timer { Interval = 30 };
        fadeTimer.Tick += Fade_Timer_Tick;
        opacityStep = 1.0f / (FadeDuration / fadeTimer.Interval);
        closeTimer = new System.Windows.Forms.Timer { Interval = ShowDuration };
        closeTimer.Tick += Close_Timer_Tick;
    }
    private void Fade_Timer_Tick(object sender, EventArgs e)
    {
        if (this.Opacity < 1.0f)
        {
            this.Opacity += opacityStep;
            if (this.Opacity >= 1.0f)
            {
                this.Opacity = 1.0f;
                fadeTimer.Stop();
            }
        }
    }
    private void Close_Timer_Tick(object sender, EventArgs e)
    {
        closeTimer.Stop();
        fadeTimer.Tick -= Fade_Timer_Tick;
        fadeTimer.Tick += FadeOutTimer_Tick;
        fadeTimer.Start();
    }
    private void FadeOutTimer_Tick(object sender, EventArgs e)
    {
        if (this.Opacity > 0.0f)
        {
            this.Opacity -= opacityStep;
            if (this.Opacity <= 0.0f)
            {
                this.Opacity = 0.0f;
                fadeTimer.Stop();
                this.Close();
            }
        }
    }
    public static void ShowBlessing(string text)
    {
        var popup = new BlessingForms(text);
        Random random = new Random();
        Screen screen = Screen.PrimaryScreen;
        int maxX = screen.WorkingArea.Width - popup.Width;
        int maxY = screen.WorkingArea.Height - popup.Height;
        int x = random.Next(0, maxX + 1);
        int y = random.Next(0, maxY + 1);
        popup.Location = new Point(x, y);
        popup.fadeTimer.Start();
        popup.closeTimer.Start();
        popup.ShowDialog();
    }
    private void InitializeComponent()
    {
        this.Label_Blessing = new System.Windows.Forms.Label();
        this.SuspendLayout();
        // 
        // Label_Blessing
        // 
        this.Label_Blessing.Dock = System.Windows.Forms.DockStyle.Fill;
        this.Label_Blessing.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
        this.Label_Blessing.ForeColor = System.Drawing.Color.FromArgb(139, 69, 19);
        this.Label_Blessing.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
        this.Label_Blessing.Padding = new System.Windows.Forms.Padding(20);
        this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 15F);
        this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
        this.ClientSize = new System.Drawing.Size(300, 150);
        this.Controls.Add(this.Label_Blessing);
        this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
        this.ShowIcon = false;
        this.StartPosition = System.Windows.Forms.FormStartPosition.Manual;
        this.ResumeLayout(false);
    }
    private System.Windows.Forms.Label Label_Blessing;
}
