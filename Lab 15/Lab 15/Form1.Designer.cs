namespace Lab_15
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.exitToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.aboutToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.sideOne = new System.Windows.Forms.TextBox();
            this.sideTwo = new System.Windows.Forms.TextBox();
            this.hypotenuse = new System.Windows.Forms.Label();
            this.angleOne = new System.Windows.Forms.Label();
            this.angleTwo = new System.Windows.Forms.Label();
            this.menuStrip1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // menuStrip1
            // 
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.exitToolStripMenuItem,
            this.aboutToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(286, 24);
            this.menuStrip1.TabIndex = 0;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // exitToolStripMenuItem
            // 
            this.exitToolStripMenuItem.Name = "exitToolStripMenuItem";
            this.exitToolStripMenuItem.Size = new System.Drawing.Size(37, 20);
            this.exitToolStripMenuItem.Text = "Exit";
            this.exitToolStripMenuItem.Click += new System.EventHandler(this.exitToolStripMenuItem_Click);
            // 
            // aboutToolStripMenuItem
            // 
            this.aboutToolStripMenuItem.Name = "aboutToolStripMenuItem";
            this.aboutToolStripMenuItem.Size = new System.Drawing.Size(52, 20);
            this.aboutToolStripMenuItem.Text = "About";
            this.aboutToolStripMenuItem.Click += new System.EventHandler(this.aboutToolStripMenuItem_Click);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(19, 0);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(255, 236);
            this.pictureBox1.TabIndex = 1;
            this.pictureBox1.TabStop = false;
            // 
            // sideOne
            // 
            this.sideOne.Location = new System.Drawing.Point(65, 172);
            this.sideOne.Name = "sideOne";
            this.sideOne.Size = new System.Drawing.Size(100, 20);
            this.sideOne.TabIndex = 2;
            this.sideOne.Text = "Side 1 Length";
            this.sideOne.TextChanged += new System.EventHandler(this.sideOne_TextChanged);
            // 
            // sideTwo
            // 
            this.sideTwo.Location = new System.Drawing.Point(65, 198);
            this.sideTwo.Name = "sideTwo";
            this.sideTwo.Size = new System.Drawing.Size(100, 20);
            this.sideTwo.TabIndex = 3;
            this.sideTwo.Text = "Side 2 Length";
            this.sideTwo.TextChanged += new System.EventHandler(this.sideTwo_TextChanged);
            // 
            // hypotenuse
            // 
            this.hypotenuse.AutoSize = true;
            this.hypotenuse.Location = new System.Drawing.Point(139, 107);
            this.hypotenuse.Name = "hypotenuse";
            this.hypotenuse.Size = new System.Drawing.Size(64, 13);
            this.hypotenuse.TabIndex = 4;
            this.hypotenuse.Text = "Hypotenuse";
            // 
            // angleOne
            // 
            this.angleOne.AutoSize = true;
            this.angleOne.Location = new System.Drawing.Point(56, 28);
            this.angleOne.Name = "angleOne";
            this.angleOne.Size = new System.Drawing.Size(43, 13);
            this.angleOne.TabIndex = 5;
            this.angleOne.Text = "Angle 1";
            // 
            // angleTwo
            // 
            this.angleTwo.AutoSize = true;
            this.angleTwo.Location = new System.Drawing.Point(231, 198);
            this.angleTwo.Name = "angleTwo";
            this.angleTwo.Size = new System.Drawing.Size(43, 13);
            this.angleTwo.TabIndex = 6;
            this.angleTwo.Text = "Angle 2";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(286, 253);
            this.Controls.Add(this.angleTwo);
            this.Controls.Add(this.angleOne);
            this.Controls.Add(this.hypotenuse);
            this.Controls.Add(this.sideTwo);
            this.Controls.Add(this.sideOne);
            this.Controls.Add(this.menuStrip1);
            this.Controls.Add(this.pictureBox1);
            this.MainMenuStrip = this.menuStrip1;
            this.Name = "Form1";
            this.Text = "Lab 15";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem exitToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem aboutToolStripMenuItem;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.TextBox sideOne;
        private System.Windows.Forms.TextBox sideTwo;
        private System.Windows.Forms.Label hypotenuse;
        private System.Windows.Forms.Label angleOne;
        private System.Windows.Forms.Label angleTwo;
    }
}

